//
//  unit rendering system.cpp
//  Classic Tower Defence
//
//  Created by Indi Kernick on 22/4/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "unit rendering system.hpp"

#include "position component.hpp"
#include "unit dir component.hpp"
#include "unit sprite component.hpp"
#include "unit walk anim component.hpp"

void unitRenderingSystem(
  ECS::Registry &reg,
  G2D::QuadWriter &writer,
  const Unpack::Spritesheet &sheet
) {
  const auto view = reg.view<Position, UnitDir, UnitSprite, UnitWalkAnim>();
  for (const ECS::EntityID entity : view) {
    const UnitSprite &sprite = view.get<UnitSprite>(entity);
    Unpack::SpriteID id = sprite.sprite;
    id += Math::toNum(view.get<UnitDir>(entity).dir, sprite.frames);
    const Unpack::Rect rect = sheet.getSprite(id);
    
    writer.quad();
    writer.tilePos(0.5f, view.get<Position>(entity).pos);
    writer.tileTex(rect.min, rect.max);
  }
}
