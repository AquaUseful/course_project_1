#pragma once

#include "Singleton.hpp"

#include <iostream>
#include <ostream>
#include <type_traits>

class Logger : public Singleton<Logger> {
  friend class Singleton<Logger>;

public:
  enum class Level { Debug = 0, Info, Warning, Error };

  const Level& loglevel() const;
  Level& loglevel();

  const Level& msg_level() const;

  const std::ostream& log_stream() const;
  std::ostream& log_stream();

  Logger& log(const Level&, const unsigned int, const char* const);

  static const char* const level_name(const Level&);

  void operator()() const;
  template <typename T, typename... Targs> void operator()(const T&, const Targs&...) const;

protected:
  Level _loglevel;
  Level _msg_level;
  std::ostream& _log_stream;

private:
  Logger();
  ~Logger() {};

  bool is_being_printed(const Level&) const;
};

template <typename T, typename... Targs> void Logger::operator()(const T& first, const Targs&... vargs) const {
  if (is_being_printed(_msg_level)) {
    _log_stream << first;
    if (sizeof...(vargs) > 0) {
      _log_stream << ' ';
    }
    (*this)(vargs...);
  }
}

#define _LOG(l) (Logger::instance().log((l), __LINE__, __FILE__))

#define LOG_DEBUG   (_LOG(Logger::Level::Debug))
#define LOG_INFO    (_LOG(Logger::Level::Info))
#define LOG_WARNING (_LOG(Logger::Level::Warning))
#define LOG_ERROR   (_LOG(Logger::Level::Error))
