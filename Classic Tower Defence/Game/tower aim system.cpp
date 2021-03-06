//
//  tower aim system.cpp
//  Classic Tower Defence
//
//  Created by Indi Kernick on 21/4/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "tower aim system.hpp"

#include <glm/glm.hpp>
#include "position component.hpp"
#include "tower target component.hpp"
#include "common tower stats component.hpp"
#include "unit move distance component.hpp"

void towerAimSystem(ECS::Registry &reg) {
  auto towers = reg.view<Position, CommonTowerStats, TowerTarget>();
  auto units = reg.view<Position, UnitMoveDistance>();
  
  for (const ECS::EntityID tower : towers) {
    const glm::vec2 towerPos = towers.get<Position>(tower).pos;
    const float range = towers.get<CommonTowerStats>(tower).range + 0.5f;
    
    float targetMoveDist = 0.0f;
    glm::vec2 targetPos;
    float targetDist = 0.0f;
    ECS::EntityID targetUnit = entt::null;
    
    for (const ECS::EntityID unit : units) {
      const glm::vec2 unitPos = units.get<Position>(unit).pos;
      const float unitDist = glm::distance(towerPos, unitPos);
      if (unitDist > range) {
        continue;
      }
    
      const float moveDist = units.get<UnitMoveDistance>(unit).dist;
      if (moveDist > targetMoveDist) {
        targetMoveDist = moveDist;
        targetUnit = unit;
        targetPos = unitPos;
        targetDist = unitDist;
      }
    }
    
    TowerTarget &target = towers.get<TowerTarget>(tower);
    target.id = targetUnit;
    if (targetUnit != entt::null) {
      target.vec = targetPos - towerPos;
      target.pos = targetPos;
      target.dist = targetDist;
      target.angle = std::atan2(target.vec.y, target.vec.x);
    }
  }
}
