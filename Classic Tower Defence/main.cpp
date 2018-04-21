//
//  main.cpp
//  Classic Tower Defence
//
//  Created by Indi Kernick on 21/4/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "Game/app.hpp"
#include <Simpleton/SDL/mainloop.hpp>
#include <Simpleton/Utils/profiler.hpp>

int main() {
  App app;
  SDL::runMainloop(&app);
  PROFILER_INFO(stdout);
  return 0;
}
