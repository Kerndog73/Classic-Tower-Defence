//
//  create base.cpp
//  Classic Tower Defence
//
//  Created by Indi Kernick on 23/4/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "create base.hpp"

#include "base gold tag.hpp"
#include "base health tag.hpp"

void createBase(ECS::Registry &reg, const int32_t health) {
  const ECS::EntityID id = reg.create();
  reg.attach<BaseHealth>(id, health);
  reg.attach<BaseGold>(id, uint32_t(0));
}
