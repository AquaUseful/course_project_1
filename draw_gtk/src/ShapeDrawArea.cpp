#include "ShapeDrawArea.hpp"
#include "DrawAdapter.hpp"
#include "Logger.hpp"
#include "Rectange.hpp"
#include "Rhombus.hpp"
#include "ComplexShape.hpp"

#include <memory>
#include <unistd.h>

draw::ShapeDrawArea::ShapeDrawArea() {
  set_draw_func(sigc::mem_fun(*this, &ShapeDrawArea::on_draw));
}

draw::ShapeDrawArea::~ShapeDrawArea() = default;

void draw::ShapeDrawArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height) {
  cr->set_source_rgb(0.0, 0.0, 0.0);
  DrawAdapterGTK adapter(cr, width, height);

  shapes::Rhombus<int> rh({100, 100}, 50);
  LOG_DEBUG("Created rhombus:", rh);

  shapes::Rectangle<int> rect({100, 100}, {10, 10});
  LOG_DEBUG("Created rect:", rect);

  const auto rh_ptr = std::make_shared<decltype(rh)>(rh);
  const auto rect_ptr = std::make_shared<decltype(rect)>(rect);

  shapes::ComplexShape<int> ch(rh_ptr, rect_ptr);

  ch.draw(adapter);
}