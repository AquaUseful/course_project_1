#include <cstdlib>
#include <functional>
#include <iostream>
#include <ostream>

#include <gtkmm/drawingarea.h>
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <cairomm/context.h>

#include "ShapeWindow.hpp"
#include "Vec.hpp"
#include "Rhombus.hpp"
#include "Rectange.hpp"
#include "Logger.hpp"

const Logger::Level level = Logger::Level::Info;

class MyArea : public Gtk::DrawingArea
{
public:
  MyArea();
  virtual ~MyArea();

protected:
  void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
};

class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow();

protected:
  MyArea m_area;
};

MyArea::MyArea()
{
  set_draw_func(sigc::mem_fun(*this, &MyArea::on_draw));
}

MyArea::~MyArea()
{
}

void MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height)
{
  // coordinates for the center of the window
  int xc, yc;
  xc = width / 2;
  yc = height / 2;

  cr->set_line_width(10.0);

  // draw red lines out from the center of the window
  cr->set_source_rgb(0.0, 0.0, 0.0);
  cr->move_to(0, 0);
  cr->line_to(xc, yc);
  cr->line_to(0, height);
  cr->move_to(xc, yc);
  cr->line_to(width, yc);
  cr->stroke();
}

ExampleWindow::ExampleWindow()
{
  set_title("DrawingArea");
  set_child(m_area);
}

int main(int argc, char** argv)
{
  auto app = Gtk::Application::create("org.gtkmm.example");

  return app->make_window_and_run<draw::ShapeWindow>(argc, argv);
}
