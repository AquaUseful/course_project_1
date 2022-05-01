#pragma once

#include <cstddef>
#include <utility>

namespace shapes {

  template <typename T> class Vec2D final {
  public:
    using coord_t = T;

    Vec2D() = default;
    Vec2D(const Vec2D&) = default;
    Vec2D(Vec2D&&) = default;

    template <typename U> Vec2D(U&& x, U&& y) : _x(std::forward<U>(x)), _y(std::forward<U>(y)) {};

    template <typename U> Vec2D(const Vec2D<U>& orig) : _x(static_cast<T>(orig.x())), _y(static_cast<T>(orig.y())) {};

    ~Vec2D() = default;

    Vec2D& operator=(const Vec2D&) = default;
    Vec2D& operator=(Vec2D&&) = default;

    Vec2D& operator*=(const coord_t& right) {
      _x *= right;
      _y *= right;
      return *this;
    }
    Vec2D& operator/=(const coord_t& right) {
      _x /= right;
      _y /= right;
      return *this;
    }
    Vec2D& operator+=(const Vec2D& right) {
      _x += right._x;
      _y += right._y;
      return *this;
    }
    Vec2D& operator-=(const Vec2D& right) {
      _x -= right._x;
      _y -= right._y;
      return *this;
    }

    template <typename U> void x(U&& x) {
      _x = std::forward<U>(x);
    }
    const coord_t& x() const {
      return _x;
    }
    template <typename U> void y(U&& y) {
      _y = std::forward<U>(y);
    }
    const coord_t& y() const {
      return _y;
    }

  protected:
    coord_t _x {0};
    coord_t _y {0};
  };

}