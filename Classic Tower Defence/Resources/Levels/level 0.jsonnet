local getSprite = import "getsprite.libsonnet";
local getSound = import "getsound.libsonnet";

{
  map: 0,
  sprite: getSprite("map 0"),
  waves: [
    {
      quantity: 10,
      stats: {
        health: 100,
        armour: 50,
        healthRegen: 0,
        armourRegen: 0,
        dodge: 0,
        moveSpeed: 2
      },
      sprite: {
        sprite: getSprite("robot 0 0"),
        frames: getSprite("robot 1 0") - getSprite("robot 0 0"),
        death: getSprite("explosion 0"),
        deathFrames: 4
      },
      sound: {
        id: getSound("robot destroyed")
      }
    }
  ]
}
