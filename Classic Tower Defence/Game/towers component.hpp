//
//  towers.hpp
//  Classic Tower Defence
//
//  Created by Indi Kernick on 21/4/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef towers_hpp
#define towers_hpp

#include <vector>
#include "sound component.hpp"
#include "tower stats component.hpp"
#include "tower sprites component.hpp"
#include "tower upgrades component.hpp"

struct TowerProto {
  Sound sound;
  TowerStatsBase stats;
  TowerSpritesBase sprites;
  TowerUpgradesBase upgrades;
};

using Towers = std::vector<TowerProto>;

#endif
