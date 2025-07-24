#include "raylib.h"
#include "common.h"
#include "rocketLauncher.h"

extern const unsigned int TARGETFPS;

Weapon createRocketLauncher(){
  Weapon rocketLauncher;
  rocketLauncher.x = 0;
  rocketLauncher.y = 0;
  rocketLauncher.width = 60;
  rocketLauncher.height = 20;
  rocketLauncher.fireRate = 3.0f * (float) TARGETFPS;
  rocketLauncher.type = "explosive";
  rocketLauncher.range = 900.0f;
  rocketLauncher.damage = 300;
  rocketLauncher.holding = false;
  return rocketLauncher;
}

