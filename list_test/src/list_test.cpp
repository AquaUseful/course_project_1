#include <cstdlib>
#include <memory>

#include "Rhombus.hpp"
#include "Shape.hpp"
#include "ShapeList.hpp"
#include "Logger.hpp"
#include "Rectange.hpp"
#include "ComplexShape.hpp"
#include "Vec.hpp"

int main() {
  LOG_INFO("Testing shape list");

  containers::ShapeList<double> lst;

  const auto rect1 = std::make_shared<shapes::Rectangle<double>>(shapes::Vec2D<double>(3.5, 0.1), shapes::Vec2D<double>(7.4, 1.1));
  const auto rect2 = std::make_shared<shapes::Rectangle<double>>(shapes::Vec2D<double>(1.5, 7.1), shapes::Vec2D<double>(64.4, 1.77));
  const auto rect3 = std::make_shared<shapes::Rectangle<double>>(shapes::Vec2D<double>(3.5, 127.1), shapes::Vec2D<double>(7.4, 79.1));

  LOG_INFO("Created rectangle:", *rect1);
  LOG_INFO("Created rectangle:", *rect2);
  LOG_INFO("Created rectangle:", *rect3);

  lst.push_back(rect1);
  LOG_INFO("Pushed", *rect1, "to back of list:", lst);
  lst.push_front(rect2);
  LOG_INFO("Pushed", *rect1, "to front back list:", lst);
  lst.push_back(rect3);
  LOG_INFO("Pushed", *rect1, "to back of list:", lst);

  const auto rh1 = std::make_shared<shapes::Rhombus<double>>(shapes::Vec2D<double>(3.5, 0.1), 48.0);
  const auto rh2 = std::make_shared<shapes::Rhombus<double>>(shapes::Vec2D<double>(1.5, 7.1), 2.3);
  const auto rh3 = std::make_shared<shapes::Rhombus<double>>(shapes::Vec2D<double>(3.5, 127.1), 7.0);

  LOG_INFO("Created rhombus:", *rh1);
  LOG_INFO("Created rhombus:", *rh2);
  LOG_INFO("Created rhombus:", *rh3);

  lst.push_front(rh1);
  LOG_INFO("Pushed", *rh2, "to front of list:", lst);
  lst.push_front(rh2);
  LOG_INFO("Pushed", *rh2, "to front back list:", lst);
  lst.push_front(rh3);
  LOG_INFO("Pushed", *rh3, "to front of list:", lst);

  const auto ch1 = std::make_shared<shapes::ComplexShape<double>>(rh1, rect1);
  const auto ch2 = std::make_shared<shapes::ComplexShape<double>>(rh2, rect2);
  const auto ch3 = std::make_shared<shapes::ComplexShape<double>>(rh3, rect3);

  LOG_INFO("Created compex shape:", *ch1);
  LOG_INFO("Created compex shape:", *ch2);
  LOG_INFO("Created compex shape:", *ch3);

  lst.push_back(ch1);
  LOG_INFO("Pushed", *ch1, "to back of list:", lst);
  lst.push_back(ch2);
  LOG_INFO("Pushed", *ch2, "to back back list:", lst);
  lst.push_back(ch3);
  LOG_INFO("Pushed", *ch3, "to back of list:", lst);

  lst.pop_front();
  LOG_INFO("Popping from front of list:", lst);

  lst.pop_back();
  LOG_INFO("Popping from back of list:", lst);

  lst.clear();
  LOG_INFO("Cleared list:", lst);

  return EXIT_SUCCESS;
}