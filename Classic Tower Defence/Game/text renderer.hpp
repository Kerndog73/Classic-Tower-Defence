//
//  text renderer.hpp
//  Classic Tower Defence
//
//  Created by Indi Kernick on 21/5/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef text_renderer_hpp
#define text_renderer_hpp

#include <Simpleton/Sprite/sheet.hpp>
#include <Simpleton/Graphics 2D/quad writer.hpp>

//@SIMPLETON

enum class Align {
  LEFT,
  CENTER,
  RIGHT
};

class TextRenderer {
  
  template <typename T, typename Ret>
  using EnableNotStr = std::enable_if_t<
    !std::is_convertible_v<T, std::string_view>,
    Ret
  >;

public:
  TextRenderer() = default;
  explicit TextRenderer(G2D::Section &);
  
  void section(G2D::Section &);
  G2D::Section &section() const;
  
  void glyphSize(glm::vec2);
  void advance(glm::vec2);
  void scale(float);
  void depth(float);
  
  template <Align ALIGN = Align::LEFT, G2D::PlusXY PLUS_XY = G2D::PlusXY::RIGHT_DOWN>
  glm::vec2 write(glm::vec2, std::string_view);
  template <Align ALIGN = Align::LEFT, G2D::PlusXY PLUS_XY = G2D::PlusXY::RIGHT_DOWN>
  glm::vec2 write(glm::vec2, char);
  template <Align ALIGN = Align::LEFT, G2D::PlusXY PLUS_XY = G2D::PlusXY::RIGHT_DOWN, typename T>
  EnableNotStr<T, glm::vec2> write(glm::vec2, const T &);
  
private:
  G2D::Section *section_ = nullptr;
  glm::vec2 glyphSize_ {1.0f};
  glm::vec2 advance_ {1.0f};
  float scale_ = 1.0f;
  float depth_ = 0.0f;

  template <G2D::PlusXY PLUS_XY>
  glm::vec2 writeLeft(glm::vec2, std::string_view);
  template <G2D::PlusXY PLUS_XY>
  void writeChar(glm::vec2, glm::vec2, char);
};

#include "text renderer.inl"

#endif
