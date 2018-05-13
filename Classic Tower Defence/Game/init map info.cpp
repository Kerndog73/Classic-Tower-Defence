//
//  init map info.cpp
//  Classic Tower Defence
//
//  Created by Indi Kernick on 21/4/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "init map info.hpp"

#include "map info tag.hpp"
#include <Simpleton/Math/dir.hpp>

namespace {
  // Finds any path between points if one exists. Handles dead ends. Gets stuck
  // in some loops but not others. Does not find the shortest path.
  // Returns true if a path was found.

  //@SIMPLETON

  bool findPath(MapInfo &info, const Map &map, const Math::Dir prevDir, const Grid::Pos pos) {
    info.path.push_back(pos);
    
    for (const Math::Dir dir : Math::DIR_RANGE) {
      if (dir == Math::opposite(prevDir)) {
        continue;
      }
      const Grid::Pos newPos = pos + Math::ToVec<Grid::Pos::value_type>::conv(dir);
      
      if (map.outOfRange(newPos)) {
        continue;
      }
      if (newPos == info.exit) {
        info.path.push_back(info.exit);
        return true;
      }
      
      if (map[newPos] == TileType::PATH) {
        if (findPath(info, map, dir, newPos)) {
          return true;
        } else {
          info.path.pop_back();
        }
      }
    }
    
    return false;
  }
}

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
  
  if (!findPath(info, map, Math::Dir::NONE, info.entry)) {
    throw std::runtime_error("Could not find path from entry to exit");
  }
  
  info.pathDist = info.path.size() - 1;
  info.entryDir = Math::FromVec<unsigned>::conv(info.path[1] - info.path[0]);
}
