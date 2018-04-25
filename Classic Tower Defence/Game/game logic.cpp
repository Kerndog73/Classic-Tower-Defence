//
//  game logic.cpp
//  Classic Tower Defence
//
//  Created by Indi Kernick on 23/4/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "game logic.hpp"

#include <string>
#include "create level.hpp"
#include "load level.hpp"
#include "map sprites component.hpp"
#include "map info component.hpp"
#include "create spawner.hpp"
#include "create tower.hpp"
#include "create base.hpp"
#include "unit motion system.hpp"
#include "unit death system.hpp"
#include "spawner system.hpp"
#include "spawner timing system.hpp"
#include "base damage system.hpp"
#include "tower aim system.hpp"
#include "tower shoot system.hpp"
#include "tower timing system.hpp"

void GameLogic::init(ECS::Registry &reg) {
  createLevel(reg);
  loadLevel(reg, 0);
  createSpawner(reg, 1.5f);
  createBase(reg, 1000);
  
  tower.stats.range = 10;
  tower.stats.damage = 20;
  tower.stats.rof = 1;
  tower.sprites.gun = 37;
  tower.sprites.firingFrames = 5;
  tower.sprites.base = 36;
  tower.upgrades.first = nullptr;
  tower.upgrades.second = nullptr;
  
  //createTower(reg, tower, {3, 5});
  createTower(reg, tower, {6, 5});
  createTower(reg, tower, {11, 4});
  createTower(reg, tower, {11, 7});
}

bool GameLogic::input(const SDL_Event &) {
  return false;
}

void GameLogic::update(ECS::Registry &reg, const float delta) {
  towerTimingSystem(reg, delta);
  spawnerTimingSystem(reg, delta);
  spawnerSystem(reg);
  
  towerAimSystem(reg);
  towerShootSystem(reg);
  
  unitMotionSystem(reg, delta);
  unitDeathSystem(reg);
  
  baseDamageSystem(reg);
}
