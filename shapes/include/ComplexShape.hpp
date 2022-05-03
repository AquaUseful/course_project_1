#pragma once

#include <memory>
#include <utility>

#include "Rectange.hpp"
#include "Rhombus.hpp"
#include "Shape.hpp"

namespace shapes {
  template <typename T> class ComplexShape final : public Shape2D<T> {
  public:
    using rectangle_t = Rectangle<T>;
    using rhombus_t = Rhombus<T>;
    using rectangle_ptr_t = std::shared_ptr<rectangle_t>;
    using rhombus_ptr_t = std::shared_ptr<rhombus_t>;

    ComplexShape() = delete;
    ComplexShape(const ComplexShape&) = default;
    ComplexShape(ComplexShape&&) noexcept = default;

    ComplexShape(const rhombus_ptr_t& rh, const rectangle_ptr_t& rect) : _rectangle_ptr(rect), _rhombus_ptr(rh) {
      fix_rectangle();
    }
    ComplexShape(rhombus_ptr_t&& rh, rectangle_ptr_t&& rect)
      : _rectangle_ptr(std::move<rectangle_ptr_t>(rect)), _rhombus_ptr(std::move<rhombus_ptr_t>(rh)) {
      fix_rectangle();
    };

    ~ComplexShape() = default;

    ComplexShape& operator=(const ComplexShape&) = default;
    ComplexShape& operator=(ComplexShape&&) = default;

    const rectangle_ptr_t& rectangle_ptr() {
      return _rectangle_ptr;
    }
    const rhombus_ptr_t& rhombus_ptr() {
      return _rhombus_ptr;
    }

    void draw(draw::DrawAdapterGTK& adapter) override {
      _rhombus_ptr->draw(adapter);
      _rectangle_ptr->draw(adapter);
    }
    void hide(draw::DrawAdapterGTK& adapter) override {
      _rhombus_ptr->hide(adapter);
      _rectangle_ptr->hide(adapter);
    }

  protected:
    rectangle_ptr_t _rectangle_ptr;
    rhombus_ptr_t _rhombus_ptr;

    void fix_rectangle() {
      _rectangle_ptr->anchor(_rhombus_ptr->anchor());
      _rectangle_ptr->size(typename rectangle_t::sz_t(_rhombus_ptr->half_diagonal(), _rhombus_ptr->half_diagonal() * 2));
    }
  };

  template <typename T> std::ostream& operator<<(std::ostream& stream, const ComplexShape<T>& ch) {
    stream << "ComplexShape(" << *ch.rectangle_ptr() << ", " << *ch.rhombus_ptr() << ')';
    return stream;
  }

}