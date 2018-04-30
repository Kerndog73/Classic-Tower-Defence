local getSprite = import "getsprite.libsonnet";
local getSound = import "getsound.libsonnet";

local towerSprites(sprite) = {
  gun: getSprite(sprite + " 0"),
  base: getSprite(sprite + " base"),
  firingFrames: $.base - $.gun,
  projectile: getSprite(sprite + " projectile")
};

[
  {
    CommonTowerStats: {
      range: 6,
      damage: 10,
      rof: 3,
      armourPiercing: 0.1
    },
    TurretTower: {},
    TowerSprites: towerSprites("blaster"),
    upgrades: {},
    Sound: {
      id: getSound("blaster")
    }
  },
  {
    CommonTowerStats: {
      range: 4,
      damage: 40,
      rof: 1/2,
      armourPiercing: 0.6
    },
    SplashTower: {
      aoe: 10
    },
    TowerEffect: {
      PoisonEffect: {
        damageFactor: 0.2,
        duration: 5
      }
    },
    TowerSprites: towerSprites("cannon"),
    upgrades: {},
    Sound: {
      id: getSound("cannon")
    }
  }
]
