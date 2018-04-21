//
//  map info.hpp
//  Classic Tower Defence
//
//  Created by Indi Kernick on 21/4/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef map_info_hpp
#define map_info_hpp

#include "map.hpp"

struct MapInfo {
  using Pos = Map::Pos;

  Pos entry;
  Pos exit;
  std::vector<Pos> path;
};

#endif
