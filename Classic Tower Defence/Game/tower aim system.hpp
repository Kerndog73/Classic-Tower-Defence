//
//  tower aim system.hpp
//  Classic Tower Defence
//
//  Created by Indi Kernick on 21/4/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef tower_aim_system_hpp
#define tower_aim_system_hpp

#include <Simpleton/ECS/registry.hpp>

// Point TowerTarget to the unit that is closest to the exit
void towerAimSystem(ECS::Registry &);

#endif
