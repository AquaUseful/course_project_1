#pragma once

#include <cmath>
#include <ostream>
#include <utility>

#include "Shape.hpp"

namespace shapes {

  template <typename T> class Rhombus final : public Shape2D<T> {
  public:
    using sz_t = T;
    using anchor_t = typename Shape2D<T>::anchor_t;

    Rhombus() = delete;
    Rhombus(const Rhombus&) = default;
    Rhombus(Rhombus&&) noexcept = default;

    Rhombus(const anchor_t& anchor, const sz_t& size) : Shape2D<T>(anchor), _size(size) {};
    Rhombus(anchor_t&& anchor, sz_t&& size) : Shape2D<T>(std::move(anchor)), _size(std::move(size)) {};

    ~Rhombus() = default;

    Rhombus& operator=(const Rhombus&) = default;
    Rhombus& operator=(Rhombus&&) = default;

    template <typename U> void size(U&& size) {
      _size = std::forward<U>(size);
    }
    const sz_t& size() const {
      return _size;
    }

    void draw(draw::DrawAdapterGTK& adapter) override {
      adapter.draw_line(top(), right());
      adapter.draw_line(top(), left());
      adapter.draw_line(right(), bottom());
      adapter.draw_line(left(), bottom());

      adapter.stroke();
    }
    void hide(draw::DrawAdapterGTK& adapter) override {
    }

    T half_diagonal() {
      return std::sqrt(2) * _size;
    }

    std::ostream& print(std::ostream& stream) const override {
      return (stream << "Rhombus(" << Shape2D<T>::anchor() << ", " << size() << ')');
    }

  protected:
    T _size {};

    anchor_t top() {
      return Shape2D<T>::anchor();
    }
    anchor_t right() {
      return Shape2D<T>::anchor() + anchor_t(half_diagonal(), half_diagonal());
    }
    anchor_t left() {
      return Shape2D<T>::anchor() + anchor_t(-half_diagonal(), half_diagonal());
    }
    anchor_t bottom() {
      return anchor_t(Shape2D<T>::anchor().x(), Shape2D<T>::anchor().y() + half_diagonal() * 2);
    }
  };

  template <typename T> std::ostream& operator<<(std::ostream& stream, const Rhombus<T>& rh) {
    return rh.print(stream);
  }

}