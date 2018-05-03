//
//  spawner state tag.hpp
//  Classic Tower Defence
//
//  Created by Indi Kernick on 21/4/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef spawner_state_tag_hpp
#define spawner_state_tag_hpp

struct SpawnerState {
  enum State {
    STARTING,
    SPAWNING,
    FINISHED
  };

  size_t currentWave;
  size_t numUnitsLeft;
  State state;
};

#endif