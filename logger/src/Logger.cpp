#include "Logger.hpp"

#include <cstdint>
#include <iostream>
#include <ostream>

Logger::Logger() : _loglevel {Level::Debug}, _log_stream {std::cerr} {};

const Logger::Level& Logger::loglevel() const {
  return _loglevel;
}
Logger::Level& Logger::loglevel() {
  return _loglevel;
}

const Logger::Level& Logger::msg_level() const {
  return _msg_level;
}

const std::ostream& Logger::log_stream() const {
  return _log_stream;
}
std::ostream& Logger::log_stream() {
  return _log_stream;
}

Logger& Logger::log(const Logger::Level& level, const unsigned int line, const char* const filename) {
  if (is_being_printed(level)) {
    _log_stream << level_name(level) << ' ' << filename << ':' << line << ": ";
  }
  _msg_level = level;
  return *this;
}

const char* const Logger::level_name(const Level& level) {
  switch (level) {
    case Level::Debug:
      return "DEBUG";
    case Level::Info:
      return "INFO";
    case Level::Warning:
      return "WARN";
    case Level::Error:
      return "ERROR";
    default:
      return "INVALID";
  }
}

void Logger::operator()() const {
  _log_stream << '\n';
}

bool Logger::is_being_printed(const Level& level) const {
  return (level >= _loglevel);
}