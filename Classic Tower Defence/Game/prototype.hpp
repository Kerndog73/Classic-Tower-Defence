//
//  prototype.hpp
//  Classic Tower Defence
//
//  Created by Indi Kernick on 27/4/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef prototype_hpp
#define prototype_hpp

#include <entt/entity/registry.hpp>

template <typename Entity, typename FamilyID = void>
class Prototype {
public:
  using entity_t = Entity;
  using registry_t = entt::Registry<Entity>;
  using family_t = entt::Family<FamilyID>;

private:
  class ComponentBase {
  public:
    virtual ~ComponentBase() = default;
    virtual void assign(registry_t &, entity_t) const = 0;
  };
  
  template <typename Comp>
  class Component : public ComponentBase {
  public:
    void assign(registry_t &registry, const entity_t entity) const override {
      registry.template assign<Comp>(entity, comp);
    }
    
    Comp comp;
  };

public:
  void operator()(registry_t &reg, const entity_t entity) const {
    for (std::unique_ptr<ComponentBase> &component : comps) {
      if (component) {
        component->assign(reg, entity);
      }
    }
  }
  entity_t operator()(registry_t &reg) const {
    const entity_t entity = reg.create();
    (*this)(reg, entity);
    return entity;
  }

  template <typename Comp>
  size_t type() const {
    return family_t::template type<Comp>();
  }

  template <typename Comp, typename ...Args>
  void assign(Args &&... args) {
    assert(!has<Comp>());
    auto component = std::make_unique<Component<Comp>>();
    component->comp = Comp {std::forward<Args>(args)...};
    const size_t index = type<Comp>();
    while (comps.size() <= index) {
      comps.emplace_back();
    }
    comps[index] = std::move(component);
  }
  
  template <typename Comp>
  void remove() {
    assert(has<Comp>());
    comps[type<Comp>()] = nullptr;
  }
  
  template <typename Comp>
  bool has() const {
    const size_t index = type<Comp>();
    return index < comps.size() && comps[index] != nullptr;
  }
  
  template <typename Comp>
  const Comp &get() const {
    assert(has<Comp>());
    return static_cast<Component<Comp> *>(comps[type<Comp>()].get())->comp;
  }
  
  template <typename Comp>
  Comp &get() {
    assert(has<Comp>());
    return static_cast<Component<Comp> *>(comps[type<Comp>()].get())->comp;
  }
  
private:
  std::vector<std::unique_ptr<ComponentBase>> comps;
};

#endif
