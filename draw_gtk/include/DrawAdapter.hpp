#pragma once

#include <array>
#include <exception>
#include <memory>
#include <tuple>
#include <type_traits>

#include "ShapeDrawArea.hpp"
#include "Vec.hpp"
#include "cairomm/context.h"
#include "cairomm/refptr.h"

namespace draw {

  class DrawAdapterGTK final {
  public:
    using cairo_ctx_t = Cairo::Context;
    using cairo_ctx_ptr_t = Cairo::RefPtr<cairo_ctx_t>;
    using area_width_t = decltype(ShapeDrawArea().get_width());
    using area_height_t = decltype(ShapeDrawArea().get_height());
    using area_size_t = shapes::Vec2D<std::common_type_t<area_width_t, area_height_t>>;

    class InvalidCoords : public std::exception {};

    DrawAdapterGTK() = delete;
    DrawAdapterGTK(const DrawAdapterGTK&) = default;
    DrawAdapterGTK(DrawAdapterGTK&&) noexcept = default;

    explicit DrawAdapterGTK(const cairo_ctx_ptr_t&, const area_width_t&, const area_height_t&);
    explicit DrawAdapterGTK(cairo_ctx_ptr_t&&, area_width_t&&, area_height_t&&);

    ~DrawAdapterGTK() = default;

    const area_size_t& area_size() const;
    void draw_line(const area_size_t&, const area_size_t&);
    void clear_line(const area_size_t&, const area_size_t&);
    void stroke();

  protected:
    cairo_ctx_ptr_t _cairo_ctx_ptr;
    area_size_t _area_size;

    constexpr static std::array<double, 3> line_color {0.0, 0.0, 0.0};
    constexpr static std::array<double, 3> bg_color {1.0, 1.0, 1.0};

    void check_coords(const area_size_t&) const;
  };

}