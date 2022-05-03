#pragma once

#include <cstddef>
#include <ostream>
#include <utility>

namespace shapes {

  template <typename T> class Vec2D final {
  public:
    using coord_t = T;

    Vec2D() = default;
    Vec2D(const Vec2D&) = default;
    Vec2D(Vec2D&&) noexcept = default;

    Vec2D(const T& x, const T& y) : _x(x), _y(y) {};
    Vec2D(T&& x, T&& y) : _x(std::move(x)), _y(std::move(y)) {};

    // template <typename U> explicit Vec2D(const Vec2D<U>& orig) : _x(static_cast<T>(orig.x())), _y(static_cast<T>(orig.y())) {};

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

  template <typename T> Vec2D<T> operator+(Vec2D<T> left, const Vec2D<T>& right) {
    return left += right;
  }
  template <typename T> Vec2D<T> operator-(Vec2D<T> left, const Vec2D<T>& right) {
    return left -= right;
  }
  template <typename T> Vec2D<T> operator*(Vec2D<T> left, const T& right) {
    return left *= right;
  }
  template <typename T> Vec2D<T> operator/(Vec2D<T> left, const T& right) {
    return left /= right;
  }

  template <typename T> std::ostream& operator<<(std::ostream& stream, const Vec2D<T>& vec) {
    stream << "Vec2D(" << vec.x() << ", " << vec.y() << ')';
    return stream;
  }

}