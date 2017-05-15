#ifndef BITMAP_HPP
#define BITMAP_HPP

#include "ray-tracing/color.hpp"

#include <vector>

using std::vector;


namespace rt {

class Bitmap {
 public:
  Bitmap(size_t width, size_t height)
    : data_(width, std::vector<Color>(height))
  {}

  Color& operator()(size_t i, size_t j) {
    return data_[i][j];
  }

  const Color& operator()(size_t i, size_t j) const {
    return data_[i][j];
  }

  size_t Width() const {
    return data_.size();
  }

  size_t Height() const {
    return data_[0].size();
  }

 private:
  vector<vector<Color>> data_;
};

}  // namespace rt

#endif
