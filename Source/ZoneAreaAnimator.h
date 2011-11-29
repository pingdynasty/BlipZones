#ifndef _ZONE_AREA_ANIMATOR_H_
#define _ZONE_AREA_ANIMATOR_H_

#include "Animator.h"
#include "Zone.h"

class ZoneAreaAnimator : public Animator {
private:
  Zone& zone;
public:
  ZoneAreaAnimator(Zone& azone) : zone(azone) {}
  void tick(uint16_t counter);
};

#endif /* _ZONE_AREA_ANIMATOR_H_ */
