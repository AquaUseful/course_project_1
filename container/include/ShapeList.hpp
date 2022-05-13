#pragma once

#include <iterator>
#include <list>
#include <memory>
#include <ostream>

#include "Shape.hpp"

namespace containers {

  template <typename T> class ShapeList final {
  public:
    using shape_t = shapes::Shape2D<T>;
    using shape_ptr_t = std::shared_ptr<shape_t>;

    ShapeList() = default;
    ShapeList(const ShapeList&) = default;
    ShapeList(ShapeList&&) noexcept = default;

    ~ShapeList() = default;

    void push_back(const shape_ptr_t& x) {
      _list.push_back(x);
    }
    void push_back(shape_ptr_t&& x) {
      _list.push_back(std::move(x));
    }

    void push_front(const shape_ptr_t& x) {
      _list.push_front(x);
    }
    void push_front(shape_ptr_t&& x) {
      _list.push_front(std::move(x));
    }

    void pop_front() {
      _list.pop_front();
    }
    void pop_back() {
      _list.pop_back();
    }

    auto front() {
      return _list.front();
    }
    auto back() {
      return _list.back();
    }

    auto begin() {
      return _list.begin();
    }
    auto end() {
      return _list.end();
    }

    void clear() {
      _list.clear();
    }

    std::ostream& print(std::ostream& stream) const {
      stream << "ShapeList(\n";
      for (auto i {_list.begin()}; i != _list.end(); ++i) {
        stream << **i << '\n';
        /*if (i != _list.rend()) {
          stream << ", ";
        }*/
      }
      stream << ')';
      return stream;
    }

  private:
    std::list<shape_ptr_t> _list;
  };

  template <typename T> std::ostream& operator<<(std::ostream& stream, const ShapeList<T>& sl) {
    return sl.print(stream);
  }

}