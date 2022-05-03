#pragma once

#include <gtkmm/drawingarea.h>

namespace draw {

  class ShapeDrawArea : public Gtk::DrawingArea {
  public:
    ShapeDrawArea();

    ~ShapeDrawArea() override;

  protected:
    void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
  };

}  // namespace draw