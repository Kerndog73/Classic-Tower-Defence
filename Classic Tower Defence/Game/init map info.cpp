//
//  init map info.cpp
//  Classic Tower Defence
//
//  Created by Indi Kernick on 21/4/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "init map info.hpp"

#include "map info tag.hpp"
#include <Simpleton/Grid/one path.hpp>

void initMapInfo(ECS::Registry &reg) {
  MapInfo &info = reg.get<MapInfo>();
  const Map &map = reg.get<Map>();
  for (size_t i = 0; i != map.scalarSize(); ++i) {
    if (map[i] == TileType::ENTRY) {
      info.entry = map.toPos(i);
    } else if (map[i] == TileType::EXIT) {
      info.exit = map.toPos(i);
    }
  }
  
  const auto notPath = [] (const TileType type) {
    return type == TileType::PLATFORM;
  };
  info.path = Grid::onePath(map, notPath, info.entry, info.exit);
  
  if (info.path.empty()) {
    throw std::runtime_error("Could not find path from entry to exit");
  }
  
  info.pathDist = info.path.size() - 1;
  info.entryDir = Math::FromVec<Grid::Coord>::conv(info.path[1] - info.path[0]);
}
