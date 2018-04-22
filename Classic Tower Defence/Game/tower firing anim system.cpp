//
//  tower firing anim system.cpp
//  Classic Tower Defence
//
//  Created by Indi Kernick on 21/4/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "tower firing anim system.hpp"

#include "tower sprites component.hpp"
#include "tower firing anim component.hpp"

void towerFiringAnimSystem(ECS::Registry &registry) {
  auto view = registry.view<TowerSprites, TowerFiringAnim>();
  for (const ECS::EntityID entity : view) {
    TowerFiringAnim &anim = view.get<TowerFiringAnim>(entity);
    if (!anim.firing) {
      continue;
    }
    const Unpack::SpriteID frames = view.get<TowerSprites>(entity).proto->firingFrames;
    
    ++anim.frame;
    if (anim.frame == frames) {
      anim.frame = 0;
    }
  }
}