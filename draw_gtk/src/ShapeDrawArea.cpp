#include "ShapeDrawArea.hpp"
#include "DrawAdapter.hpp"
#include "Logger.hpp"
#include "Rectange.hpp"
#include "Rhombus.hpp"
#include "ComplexShape.hpp"

#include <exception>
#include <memory>
#include <unistd.h>

draw::ShapeDrawArea::ShapeDrawArea() {
  set_draw_func(sigc::mem_fun(*this, &ShapeDrawArea::on_draw));
}

draw::ShapeDrawArea::~ShapeDrawArea() = default;

void draw::ShapeDrawArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height) {

  DrawAdapterGTK adapter(cr, width, height);

  const auto rh = std::make_shared<shapes::Rhombus<int>>(shapes::Vec2D<int>(100, 100), 50);
  LOG_DEBUG("Created rhombus:", *rh);

  const auto rect = std::make_shared<shapes::Rectangle<int>>(shapes::Vec2D<int>(100, 100), shapes::Vec2D<int>(10, 10));
  LOG_DEBUG("Created rect:", *rect);

  auto ch = std::make_shared<shapes::ComplexShape<int>>(rh, rect);
  LOG_DEBUG("Created compex shape:", *ch);

  ch.reset();
  LOG_DEBUG(ch);

  const auto test_rect = std::make_shared<shapes::Rectangle<int>>(shapes::Vec2D<int>(200, 100), shapes::Vec2D<int>(50, 80));

  const auto test_rhombus = std::make_shared<shapes::Rhombus<int>>(shapes::Vec2D<int>(300, 150), 50);

  try {
    // ch.draw(adapter);
    rh->draw(adapter);
    test_rect->draw(adapter);
    // test_rhombus->draw(adapter);
  } catch (DrawAdapterGTK::InvalidCoords) {
    LOG_ERROR("Trying to draw outside of drawing area");
  }
}