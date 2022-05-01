#include <cstdlib>
#include <functional>
#include <iostream>
#include <ostream>

#include "Vec.hpp"
#include "Rhombus.hpp"
#include "Rectange.hpp"
#include "Logger.hpp"

const Logger::Level level = Logger::Level::Info;

int main() {

  Logger::instance().loglevel() = level;

  shapes::Rhombus<int> r(shapes::Vec2D<int>(10, 5), 5);

  return EXIT_SUCCESS;
}
