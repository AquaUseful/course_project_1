#include "ShapeWindow.hpp"

static const char* const window_title {"Shape drawing area"};

draw::ShapeWindow::ShapeWindow() {
  set_title(window_title);
  set_child(_draw_area);
}
