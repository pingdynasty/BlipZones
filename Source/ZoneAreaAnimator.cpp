#include "ZoneAreaAnimator.h"
#include "ApplicationConfiguration.h"

#include <algorithm>

// #ifdef max
// #undef max
// #endif
// #ifdef min
// #undef min
// #endif

void ZoneAreaAnimator::tick(uint16_t counter){
  ApplicationConfiguration::getBlipSim()->clear();
  ApplicationConfiguration::getBlipSim()->
    fill(std::min(zone.from.getColumn(), zone.to.getColumn()),
	 std::min(zone.from.getRow(), zone.to.getRow()),
	 std::max(zone.from.getColumn(), zone.to.getColumn()),
	 std::max(zone.from.getRow(), zone.to.getRow()), 0x80);
  ApplicationConfiguration::getBlipSim()->flip();
}
