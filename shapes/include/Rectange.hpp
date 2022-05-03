#pragma once

#include <cmath>
#include <utility>

#include "Shape.hpp"
#include "Vec.hpp"
#include "DrawAdapter.hpp"
#include "Logger.hpp"

namespace shapes {

  template <typename T> class Rectangle final : public Shape2D<T> {
  public:
    using sz_t = Vec2D<T>;
    using anchor_t = typename Shape2D<T>::anchor_t;

    Rectangle() = delete;
    Rectangle(const Rectangle&) = default;
    Rectangle(Rectangle&&) noexcept = default;

    Rectangle(const anchor_t& anchor, const sz_t& size) : Shape2D<T>(anchor), _size(size) {};
    Rectangle(anchor_t&& anchor, sz_t&& size) : Shape2D<T>(std::move(anchor)), _size(std::move(size)) {};

    ~Rectangle() = default;

    Rectangle& operator=(const Rectangle&) = default;
    Rectangle& operator=(Rectangle&&) = default;

    template <typename U> void size(U&& size) {
      _size = std::forward<U>(size);
    }
    const sz_t& size() const {
      return _size;
    }

    void draw(draw::DrawAdapterGTK& adapter) override {
      adapter.draw_line(top_left(), top_right());
      adapter.draw_line(top_left(), bottom_left());
      adapter.draw_line(top_right(), bottom_right());
      adapter.draw_line(bottom_left(), bottom_right());

      adapter.stroke();
    }
    void hide(draw::DrawAdapterGTK& adapter) override {
      adapter.clear_line(top_left(), top_right());
      adapter.clear_line(top_left(), bottom_left());
      adapter.clear_line(top_right(), bottom_right());
      adapter.clear_line(bottom_left(), bottom_right());

      adapter.stroke();
    }

  protected:
    sz_t _size {};

    sz_t top_left() {
      return Shape2D<T>::anchor();
    }
    sz_t top_right() {
      return Vec2D<T>(Shape2D<T>::anchor().x() + _size.x(), Shape2D<T>::anchor().y());
    }
    sz_t bottom_left() {
      return Vec2D<T>(Shape2D<T>::anchor().x(), Shape2D<T>::anchor().y() + _size.y());
    }
    sz_t bottom_right() {
      return Shape2D<T>::anchor() + _size;
    }
  };

  template <typename T> std::ostream& operator<<(std::ostream& stream, const Rectangle<T>& rect) {
    stream << "Rectangle(" << rect.anchor().x() << ", " << rect.anchor().y() << ", " << rect.size() << ')';
    return stream;
  }

}