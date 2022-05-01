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
    ComplexShape(ComplexShape&&) = default;

    ComplexShape(const rectangle_ptr_t& rect, const rhombus_ptr_t& rh) : _rectangle_ptr(rect), _rhombus_ptr(rh) {};
    ComplexShape(rectangle_ptr_t&& rect, rhombus_ptr_t&& rh)
      : _rectangle_ptr(std::move<rectangle_ptr_t>(rect)), _rhombus_ptr(std::move<rhombus_ptr_t>(rh)) {};

    ~ComplexShape() = default;

    ComplexShape& operator=(const ComplexShape&) = default;
    ComplexShape& operator=(ComplexShape&&) = default;

    const rectangle_ptr_t& rectangle_ptr() {
      return _rectangle_ptr;
    }
    const rhombus_ptr_t& rhombus_ptr() {
      return _rhombus_ptr;
    }

    void draw() override {
      _rhombus_ptr->draw();
      _rectangle_ptr->draw();
    }
    void hide() override {
      _rhombus_ptr->hide();
      _rectangle_ptr->hide();
    }

  protected:
    rectangle_ptr_t _rectangle_ptr;
    rhombus_ptr_t _rhombus_ptr;
  };
}