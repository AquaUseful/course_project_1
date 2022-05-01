#pragma once

#include <utility>

#include "Shape.hpp"
#include "Vec.hpp"

namespace shapes {

  template <typename T> class Rectangle final : public Shape2D<T> {
  public:
    using sz_t = Vec2D<T>;
    using anchor_t = typename Shape2D<T>::anchor_t;

    Rectangle() = delete;
    Rectangle(const Rectangle&) = default;
    Rectangle(Rectangle&&) = default;

    Rectangle(const anchor_t& anchor, const sz_t& size) : Shape2D<T>(anchor), _size(size) {};
    Rectangle(anchor_t&& anchor, sz_t&& size) : Shape2D<T>(std::move<anchor_t>(anchor)), _size(std::move<sz_t>(size)) {};

    ~Rectangle() = default;

    Rectangle& operator=(const Rectangle&) = default;
    Rectangle& operator=(Rectangle&&) = default;

    template <typename U> void size(U&& anchor) {
      _size = std::forward<U>(anchor);
    }
    const sz_t& size() {
      return _size;
    }

    void draw() override {
    }
    void hide() override {
    }

  protected:
    sz_t _size {};
  };

}