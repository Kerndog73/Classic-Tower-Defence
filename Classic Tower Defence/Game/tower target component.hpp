//
//  tower target component.hpp
//  Classic Tower Defence
//
//  Created by Indi Kernick on 21/4/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef tower_target_component_hpp
#define tower_target_component_hpp

#include <glm/vec2.hpp>
#include <Simpleton/ECS/registry.hpp>

struct TowerTarget {
  glm::vec2 vec {0.0f};
  glm::vec2 pos {0.0f};
  float angle = 0.0f;
  float dist = 0.0f;
  ECS::EntityID id = entt::null;
};

#endif
