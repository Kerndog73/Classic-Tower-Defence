//
//  unit death system.cpp
//  Classic Tower Defence
//
//  Created by Indi Kernick on 21/4/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "unit death system.hpp"

#include "base gold tag.hpp"
#include "sound component.hpp"
#include "position component.hpp"
#include "unit stats component.hpp"
#include "unit sprite component.hpp"
#include "unit death anim component.hpp"

void unitDeathSystem(ECS::Registry &reg) {
  auto view = reg.view<Position, UnitStats, UnitSprite, Sound>();
  for (const ECS::EntityID entity : view) {
    const UnitStats stats = view.get<UnitStats>(entity);
    if (stats.health <= 1.0f) {
      reg.get<BaseGold>().gold += stats.gold;
      const Position pos = view.get<Position>(entity);
      const UnitSprite sprite = view.get<UnitSprite>(entity);
      const Sound sound = view.get<Sound>(entity);
      reg.destroy(entity);
      
      const ECS::EntityID deadUnit = reg.create();
      reg.assign<Position>(deadUnit, pos);
      reg.assign<UnitDeathAnim>(deadUnit);
      reg.assign<UnitSprite>(deadUnit, sprite);
      reg.assign<Sound>(deadUnit, sound);
    }
  }
}
