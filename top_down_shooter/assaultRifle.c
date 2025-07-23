#include "raylib.h"
#include "weapon.h"
#include "assaultRifle.h"

extern const unsigned int TARGETFPS;

Weapon createAssaultRifle(){
  Weapon assualtRifle;
  assualtRifle.x = 0;
  assualtRifle.y = 0;
  assualtRifle.width = 40;
  assualtRifle.height = 10;
  assualtRifle.range = 750.0f;
  assualtRifle.damage = 70;
  assualtRifle.fireRate = 0.2 * (float) TARGETFPS;
  assualtRifle.holding = false;
  return assualtRifle;
}
