#define BOOST_ALL_NO_LIBS
#include <asio.hpp>
#include <asio/serial_port.hpp> 
#include "AsioSerial.h"

Serial* Serial::createSerial(){
  return new AsioSerial();
}

asio::io_service io_service;
asio::serial_port sport(io_service);

int AsioSerial::connect(){
  try{
    std::string str = (const char*)port.toUTF8();
    sport.open(str);
    if(!sport.is_open())
      return -1;
    typedef asio::serial_port_base asios;
    sport.set_option( asios::baud_rate( speed ) );
    sport.set_option( asios::flow_control( asios::flow_control::none ) );
    sport.set_option( asios::parity( asios::parity::none ) );
    sport.set_option( asios::stop_bits( asios::stop_bits::one ) );
    sport.set_option( asios::character_size( 8 ) );
    connected = true;
    return 0;
  }catch(asio::system_error exc){
    return -1;
  }
}

int AsioSerial::disconnect(){
  try{
    sport.close();
    connected = false;
    return 0;
  }catch(asio::system_error exc){
    return -1;
  }
}

bool AsioSerial::isConnected(){
  return sport.is_open();
}

size_t AsioSerial::readSerial(unsigned char* data, size_t len){
  return sport.read_some(asio::buffer(data, len));
//   sport.async_read_some( asio::buffer(data, len),
// 			bind(&my_client::read_done,
// 				    shared_from_this(),
// 				    asio::placeholders::error,
// 				    asio::placeholders::bytes_transferred));
}

size_t AsioSerial::writeSerial(unsigned char* data, size_t len){
  return sport.write_some(asio::buffer(data, len));
}
