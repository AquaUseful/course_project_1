#pragma once

#include <ostream>
#include <utility>

#include "Vec.hpp"
#include "DrawAdapter.hpp"

namespace shapes {

  template <typename T> class Shape2D {
  public:
    using anchor_t = Vec2D<T>;
    // typedef Vec2D<T> anchor_t;

    Shape2D() = default;
    Shape2D(const Shape2D&) = default;
    Shape2D(Shape2D&&) noexcept = default;

    explicit Shape2D(const anchor_t& anchor) : _anchor(anchor) {};
    explicit Shape2D(anchor_t&& anchor) : _anchor(std::move(anchor)) {};
    template <typename U> Shape2D(U&& x, U&& y) : _anchor(std::forward<U>(x), std::forward<U>(y)) {};

    virtual ~Shape2D() = default;

    virtual Shape2D& operator=(const Shape2D&) = default;
    virtual Shape2D& operator=(Shape2D&&) = default;

    template <typename U> void anchor(U&& anchor) {
      _anchor = std::forward<U>(anchor);
    }
    const anchor_t& anchor() const {
      return _anchor;
    }

    virtual void draw(draw::DrawAdapterGTK& adapter) {
    }
    virtual void hide(draw::DrawAdapterGTK& adapter) {
    }
    virtual void move(const anchor_t& new_anchor, draw::DrawAdapterGTK& adapter) {
      hide(adapter);
      _anchor = new_anchor;
      draw(adapter);
    }
    virtual void move(anchor_t&& new_anchor, draw::DrawAdapterGTK& adapter) {
      hide(adapter);
      _anchor = std::move(new_anchor);
      draw(adapter);
    }

  protected:
    anchor_t _anchor {};
  };

  template <typename T> std::ostream& operator<<(std::ostream& stream, const Shape2D<T>& shape) {
    stream << "Shape2D(" << shape.anchor().x() << ", " << shape.anchor().y() << ')';
    return stream;
  }

}