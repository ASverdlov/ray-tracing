#ifndef WINDOW_HPP
#define WINDOW_HPP

namespace rt {

class Window {
 public:
  Window() {}
  Window(int width, int height) : width(width_), height(height_) {}

  void SetResolution(int width, int height) {
    width = width_;
    height = height_;
  };

  void Show(const Frame& frame);

 private:
  int width_;
  int height_;
};

}  // namespace rt

#endif
