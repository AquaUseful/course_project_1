#pragma once

#include <utility>

#include "Shape.hpp"

namespace shapes {

  template <typename T> class Rhombus final : public Shape2D<T> {
  public:
    using sz_t = T;
    using anchor_t = typename Shape2D<T>::anchor_t;

    Rhombus() = delete;
    Rhombus(const Rhombus&) = default;
    Rhombus(Rhombus&&) = default;

    Rhombus(const anchor_t& anchor, const sz_t& size) : Shape2D<T>(anchor), _size(size) {};
    Rhombus(anchor_t&& anchor, sz_t&& size) : Shape2D<T>(std::move(anchor)), _size(std::move(size)) {};

    ~Rhombus() = default;

    Rhombus& operator=(const Rhombus&) = default;
    Rhombus& operator=(Rhombus&&) = default;

    template <typename U> void size(U&& size) {
      _size = std::forward<U>(size);
    }
    const sz_t& size() {
      return _size;
    }

    void draw() override {
    }
    void hide() override {
    }

  protected:
    T _size {};
  };
}