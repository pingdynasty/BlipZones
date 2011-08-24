#include "spi.h"
#include <iostream>

void spi_init() {
  std::cout << "spi init" << std::endl;
}

void spi_cs_toggle() {
  std::cout << "spi cs toggle" << std::endl;
}

void spi_cs(bool selected) {
  std::cout << "spi cs " << selected << std::endl;
}

void spi_send(uint8_t data){
  std::cout << "spi tx 0x" << std::hex << (int)data << std::endl;
}
