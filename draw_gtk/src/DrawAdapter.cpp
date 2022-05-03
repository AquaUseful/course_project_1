#include "DrawAdapter.hpp"
#include <memory>
#include <utility>

draw::DrawAdapterGTK::DrawAdapterGTK(const cairo_ctx_ptr_t& ctx, const area_width_t& width, const area_height_t& height)
  : _cairo_ctx_ptr(ctx), _area_size(width, height) {};

draw::DrawAdapterGTK::DrawAdapterGTK(cairo_ctx_ptr_t&& ctx, area_width_t&& width, area_height_t&& height)
  : _cairo_ctx_ptr(std::move(ctx)), _area_size(std::move(width), std::move(height)) {};

const draw::DrawAdapterGTK::area_size_t& draw::DrawAdapterGTK::area_size() const {
  return _area_size;
}

void draw::DrawAdapterGTK::draw_line(const area_size_t& from, const area_size_t& to) {
  _cairo_ctx_ptr->set_source_rgb(line_color[0], line_color[1], line_color[2]);
  _cairo_ctx_ptr->move_to(from.x(), from.y());
  _cairo_ctx_ptr->line_to(to.x(), to.y());
}

void draw::DrawAdapterGTK::clear_line(const area_size_t& from, const area_size_t& to) {
  _cairo_ctx_ptr->set_source_rgb(bg_color[0], bg_color[1], bg_color[2]);
  _cairo_ctx_ptr->move_to(from.x(), from.y());
  _cairo_ctx_ptr->line_to(to.x(), to.y());
}

void draw::DrawAdapterGTK::stroke() {
  _cairo_ctx_ptr->stroke();
}
