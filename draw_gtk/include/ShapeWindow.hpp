#pragma once

#include <gtkmm/window.h>

#include "ShapeDrawArea.hpp"

namespace draw {

  class ShapeWindow final : public Gtk::Window {
  public:
    ShapeWindow();

  protected:
    draw::ShapeDrawArea _draw_area;
  };

} // namespace draw
