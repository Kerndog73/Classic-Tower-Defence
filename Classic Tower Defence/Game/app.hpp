//
//  app.hpp
//  Classic Tower Defence
//
//  Created by Indi Kernick on 21/4/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef app_hpp
#define app_hpp

#include "ui view.hpp"
#include "game view.hpp"
#include "game logic.hpp"
#include "sound queue.hpp"
#include <Simpleton/SDL/library.hpp>
#include <Simpleton/ECS/registry.hpp>
#include <Simpleton/OpenGL/context.hpp>
#include <Simpleton/SDL/audio library.hpp>
#include <Simpleton/Graphics 2D/renderer.hpp>
#include <Simpleton/Graphics 2D/quad writer.hpp>

class App {
public:
  App() = default;

  bool mainloop(uint64_t);

  void init();
  void quit();

private:
  SDL::Library windowLibrary;
  SDL::AudioLibrary audioLib;
  SDL::Window window;
  GL::Context renderingContext;
  G2D::Renderer renderer;
  ECS::Registry reg;
  G2D::QuadWriter writer;
  SoundQueue sounds;
  
  GameView view;
  GameLogic logic;
  UIView uiView;

  bool input();
  void update(float);
  void render(float);
};

#endif
