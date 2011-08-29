#include "TermiosSerial.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <iostream>

Serial* Serial::createSerial(){
  return new TermiosSerial();
}

int TermiosSerial::connect(){
  fd = openSerial(port.toUTF8(), speed);
  if(fd < 0){
    perror(port.toUTF8()); 
    return -1; 
  }
  if(verbose)
    std::cout << "tty " << port << " at " << speed << " baud" << std::endl;
//     fcntl(fd, F_SETFL, FNDELAY); // set non-blocking read
    fcntl(fd, F_SETFL, 0); // set blocking read
    //     fcntl(fd, F_SETFL, O_APPEND); // append output
    //     fcntl(fd, F_NOCACHE, 1); // turn caching off
    connected = true;
    return 0;
  }

int TermiosSerial::openSerial(const char* serialport, int baud) {
  struct termios toptions;
  int fd;
  fd = open(serialport, O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd == -1)  {
    perror(serialport);
    return -1;
  }
  if(tcgetattr(fd, &toptions) < 0) {
    perror(serialport);
    return -1;
  }
  oldtio = toptions;
  cfsetispeed(&toptions, baud);
  cfsetospeed(&toptions, baud);
  //     cfmakeraw(&tio);
  // 8N1
  toptions.c_cflag &= ~PARENB;
  toptions.c_cflag &= ~CSTOPB;
  toptions.c_cflag &= ~CSIZE;
  toptions.c_cflag |= CS8;
  // no flow control
  toptions.c_cflag &= ~CRTSCTS;
  toptions.c_cflag |= CREAD | CLOCAL;  // turn on READ & ignore ctrl lines
  toptions.c_iflag &= ~(IXON | IXOFF | IXANY); // turn off s/w flow ctrl
  toptions.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); // make raw
  toptions.c_oflag &= ~OPOST; // make raw
  // see: http://unixwiz.net/techtips/termios-vmin-vtime.html
  toptions.c_cc[VMIN]  = 0;
  toptions.c_cc[VTIME] = 20;
  if(tcsetattr(fd, TCSANOW, &toptions) < 0) {
    perror(serialport);
    return -1;
  }
  return fd;
}

ssize_t TermiosSerial::readSerial(unsigned char* data, ssize_t len){
  return read(fd, data, len);
}

ssize_t TermiosSerial::writeSerial(unsigned char* data, ssize_t len){
  if(verbose){
    std::cout << "tx\t";
    log(data, len);
  }
  return write(fd, data, len);
}

bool TermiosSerial::checkConnection(){
  struct flock fl;
  fl.l_type   = F_WRLCK;  /* F_RDLCK, F_WRLCK, F_UNLCK */
  fl.l_whence = SEEK_SET; /* SEEK_SET, SEEK_CUR, SEEK_END */
  fl.l_start  = 0; /* Offset from l_whence */
  fl.l_len    = 0; /* length, 0 = to EOF */
  fl.l_pid    = getpid();
  int ret = fcntl(fd, F_GETLK, &fl);
  if(ret < 0 || fl.l_pid != getpid()){
    disconnect();
    return false;
  }
  return true;
}

bool TermiosSerial::drain(){
  return tcdrain(fd) != -1;
}

int TermiosSerial::disconnect(){
  if(running)
    stop();
  if(connected){
    if(verbose)
      std::cout << "disconnecting" << std::endl;
    tcsetattr(fd, TCSANOW, &oldtio);
    close(fd);
    connected = false;
  }
  return 0;
}
