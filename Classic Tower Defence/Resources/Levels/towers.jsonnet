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
    local tower = self,
    ProjectileTower: {},
    CommonTowerStats: {
      range: 6,
      damage: 10,
      rof: 3,
      armourPiercing: 0.1
    },
    TowerGold: {
      buy: 100,
      sell: 50
    },
    TurretTower: {},
    TowerSprites: towerSprites("blaster"),
    upgrades: {},
    Sound: {
      id: getSound("blaster")
    },
    TowerFiringAnim: {
      frames: tower.TowerSprites.firingFrames
    }
  },
  {
    local tower = self,
    BeamTower: {},
    TurretTower: {},
    CommonTowerStats: {
      range: 10,
      damage: 5,
      rof: 20,
      armourPiercing: 0.2
    },
    TowerGold: {
      buy: 150,
      sell: 100
    },
    TowerSprites: towerSprites("laser"),
    upgrades: {},
    Sound: {
      id: getSound("blaster 1")
    },
    TowerFiringAnim: {
      frames: tower.TowerSprites.firingFrames
    },
    TowerBeamAnim: {},
  },
  {
    local tower = self,
    ProjectileTower: {},
    CommonTowerStats: {
      range: 6,
      damage: 50,
      rof: 1/3,
      armourPiercing: 0.6
    },
    TowerGold: {
      buy: 150,
      sell: 100
    },
    TurretTower: {},
    TowerSprites: towerSprites("plasma"),
    upgrades: {},
    Sound: {
      id: getSound("plasma")
    },
    TowerFiringAnim: {
      frames: tower.TowerSprites.firingFrames
    }
  },
  {
    local tower = self,
    ProjectileTower: {},
    CommonTowerStats: {
      range: 6,
      damage: 60,
      rof: 1/2,
      armourPiercing: 0.5
    },
    TowerGold: {
      buy: 100,
      sell: 50
    },
    TowerSprites: towerSprites("cannon"),
    upgrades: {},
    Sound: {
      id: getSound("cannon")
    },
    TowerFiringAnim: {
      frames: tower.TowerSprites.firingFrames
    }
  },
  {
    local tower = self,
    ProjectileTower: {},
    CommonTowerStats: {
      range: 4,
      damage: 50,
      rof: 1/2,
      armourPiercing: 0.6
    },
    TowerGold: {
      buy: 100,
      sell: 50
    },
    SplashTower: {
      aoe: 3
    },
    TowerEffect: {
      # is this necessary?
      PoisonEffect: {
        damageFactor: 0.0,
        duration: 0
      }
    },
    TowerSprites: towerSprites("explosive cannon"),
    upgrades: {},
    Sound: {
      id: getSound("cannon")
    },
    TowerFiringAnim: {
      frames: tower.TowerSprites.firingFrames
    }
  },
  {
    local tower = self,
    ProjectileTower: {},
    CommonTowerStats: {
      range: 4,
      damage: 20,
      rof: 1/4,
      armourPiercing: 0.6
    },
    TowerGold: {
      buy: 100,
      sell: 50
    },
    SplashTower: {
      aoe: 3
    },
    TowerEffect: {
      PoisonEffect: {
        damageFactor: 0.2,
        duration: 2
      }
    },
    TowerSprites: towerSprites("poison cannon"),
    upgrades: {},
    Sound: {
      id: getSound("cannon")
    },
    TowerFiringAnim: {
      frames: tower.TowerSprites.firingFrames
    }
  },
  {
    local tower = self,
    ProjectileTower: {},
    CommonTowerStats: {
      range: 4,
      damage: 5,
      rof: 1/2,
      armourPiercing: 0.4
    },
    TowerGold: {
      buy: 100,
      sell: 50
    },
    SplashTower: {
      aoe: 3
    },
    TowerEffect: {
      SlowEffect: {
        speedFactor: 0.5,
        duration: 4
      }
    },
    TowerSprites: towerSprites("snowball"),
    upgrades: {},
    Sound: {
      id: getSound("cannon")
    },
    TowerFiringAnim: {
      frames: tower.TowerSprites.firingFrames
    }
  },
  {
    local tower = self,
    ProjectileTower: {},
    CommonTowerStats: {
      range: 4,
      damage: 5,
      rof: 1/8,
      armourPiercing: 0.4
    },
    TowerGold: {
      buy: 100,
      sell: 50
    },
    SplashTower: {
      aoe: 3
    },
    TowerEffect: {
      SlowEffect: {
        speedFactor: 0,
        duration: 2
      }
    },
    TowerSprites: towerSprites("iceball"),
    upgrades: {},
    Sound: {
      id: getSound("cannon")
    },
    TowerFiringAnim: {
      frames: tower.TowerSprites.firingFrames
    }
  },
  {
    local tower = self,
    BeamTower: {},
    CommonTowerStats: {
      range: 2,
      damage: 10,
      rof: 20,
      armourPiercing: 0.1
    },
    TowerGold: {
      buy: 150,
      sell: 100
    },
    SplashTower: {
      aoe: 2
    },
    TowerEffect: {
      PoisonEffect: {
        damageFactor: 0,
        duration: 2
      }
    },
    TowerSprites: {
      local sprite = "flamethrower",

      gun: getSprite(sprite + " 0"),
      base: getSprite(sprite + " base"),
      firingFrames: self.base - self.gun,
      projectile: getSprite("fire 0")
    },
    upgrades: {},
    Sound: {
      id: getSound("blaster 1")
    },
    TowerFiringAnim: {
      frames: tower.TowerSprites.firingFrames
    },
    TowerBeamAnim: {
      frames: 4,
      scaleBeam: false
    },
  },
]
