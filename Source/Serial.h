#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <iostream>

#define BUFFER_LENGTH 2048
#define DEFAULT_SPEED B38400
#define DEFAULT_PORT "/dev/ttyS1"

class Serial {
private:
  int m_fd;
  struct termios m_oldtio;
  juce::String m_port;
  int m_speed;
  bool m_verbose;
  bool m_connected, m_running;

public:
  Serial(const juce::String& port, int speed, bool verbose = true)
    : m_port(port), m_speed(speed), m_verbose(verbose){
  }

  Serial() :
    m_port(T(DEFAULT_PORT)),
    m_speed(DEFAULT_SPEED){
  }

  virtual ~Serial(){
    if(m_running)
      stop();
    if(m_connected)
      disconnect();
  }

  juce::String& getPort(){
    return m_port;
  }

  int getSpeed(){
    return m_speed;
  }

  virtual int connect(){
    m_fd = openSerial(m_port.toUTF8(), m_speed);
    if(m_fd < 0){
      perror(m_port.toUTF8()); 
      return -1; 
    }
    if(m_verbose)
      std::cout << "tty " << m_port.toUTF8() << " at " << m_speed << " baud" << std::endl;
//     fcntl(m_fd, F_SETFL, FNDELAY); // set non-blocking read
    fcntl(m_fd, F_SETFL, 0); // set blocking read

    //     fcntl(fd, F_SETFL, O_APPEND); // append output
    //     fcntl(fd, F_NOCACHE, 1); // turn caching off
    m_connected = true;
    return 0;
  }

  int stop(){
    if(m_verbose)
      std::cout << "stopping" << std::endl;
    m_running = false;
    return 0;
  }

  int start(){
    m_running = true;
    return 0;
  }

  virtual int handle(unsigned char* data, ssize_t len){
    return len;
  }

  virtual void run(){
    ssize_t len;
    unsigned char buf[BUFFER_LENGTH];
    int used = 0;
    int frompos = 0;
    int topos = 0;

    if(m_verbose)
      std::cout << "starting rx" << std::endl;

    while(m_running) {
      len = read(m_fd, &buf[topos], BUFFER_LENGTH-topos);

//       if(len > 0){
// 	if(m_verbose){
// 	  std::cout << "rx\t";
// 	  log(&buf[frompos], len);
// 	}
// 	used = handle(&buf[frompos], len);
//       }
//     }

      topos += len;
      len = topos-frompos;
      if(len > 0){
	if(m_verbose){
	  std::cout << "rx\t";
	  log(&buf[frompos], len);
	}
	used = handle(&buf[frompos], len);
        if(used == len)
          frompos = topos = 0;
        else
          frompos += used;
// 	len = topos-frompos;
      }
      if(topos >= BUFFER_LENGTH-1){
        std::cerr << "buffer overflow!" << std::endl;
        frompos = topos = 0;
      }
    }

    if(m_verbose)
      std::cout << "stopping rx" << std::endl;
  }

  int openSerial(const char* serialport, int baud) {
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
    m_oldtio = toptions;
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

  ssize_t readSerial(unsigned char* data, ssize_t len){
    return read(m_fd, data, len);
  }

  ssize_t writeSerial(unsigned char* data, ssize_t len){
    if(m_verbose){
      std::cout << "tx\t";
      log(data, len);
    }
    return write(m_fd, data, len);
  }

  bool connected(){
    return m_connected;
  }

  virtual int disconnect(){
    if(m_connected){
      if(m_verbose)
	std::cout << "disconnecting" << std::endl;
      tcsetattr(m_fd, TCSANOW, &m_oldtio);
      close(m_fd);
      m_connected = false;
    }
    return 0;
  }

private:
  void log(unsigned char* data, ssize_t len){
    for(int i=0; i<len; ++i)
      std::cout << "0x" << std::hex << (int)data[i] << "\t";
    std::cout << std::endl;
  }
};

#endif  // __SERIAL_H__
