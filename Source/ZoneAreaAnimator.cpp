#include "ZoneAreaAnimator.h"
#include "globals.h"

void ZoneAreaAnimator::tick(uint16_t counter){
  blipbox.leds.clear();
  for(int x=std::min(zone->from.getColumn(), zone->to.getColumn()); x<std::max(zone->from.getColumn(), zone->to.getColumn()); ++x)
    for(int y=std::min(zone->from.getRow(), zone->to.getRow()); y<std::max(zone->from.getRow(), zone->to.getRow()); ++y)
      blipbox.leds.setLed(x, y, 0x80);
  blipbox.leds.flip();
}
