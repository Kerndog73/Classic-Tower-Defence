//
//  tower rendering system.cpp
//  Classic Tower Defence
//
//  Created by Indi Kernick on 23/4/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "tower rendering system.hpp"

#include "position component.hpp"
#include "tower target component.hpp"
#include "tower sprites component.hpp"
#include "tower firing anim component.hpp"

void towerRenderingSystem(
  ECS::Registry &reg,
  G2D::QuadWriter &writer,
  const Sprite::Sheet &sheet
) {
  const auto view = reg.view<Position, TowerTarget, TowerFiringAnim, TowerSprites>();
  for (const ECS::EntityID entity : view) {
    const TowerSpritesBase sprites = *view.get<TowerSprites>(entity).proto;
    const Sprite::ID frame = view.get<TowerFiringAnim>(entity).frame;
    const Sprite::ID gun = sprites.gun + frame;
    const glm::vec2 pos = view.get<Position>(entity).pos;
    const TowerTarget target = view.get<TowerTarget>(entity);
    
    writer.quad();
    writer.depth(0.5f);
    writer.tilePos(pos);
    writer.tileTex(sheet.getSprite(sprites.base));
    
    writer.quad();
    writer.depth(0.4f);
    writer.rotTilePos(target.angle, pos);
    writer.tileTex(sheet.getSprite(gun));
    
    if (frame != 0) {
      const float progress = static_cast<float>(frame) / sprites.firingFrames;
      writer.quad();
      writer.depth(0.45f);
      writer.rotTilePos(target.angle, pos + target.vec * progress);
      writer.tileTex(sheet.getSprite(sprites.projectile));
    }
  }
}
