#ifndef WINDOW_HPP
#define WINDOW_HPP

namespace rt {

struct Resolution {
  Resolution() {}
  Resolution(int width, int height) {}

  int width;
  int height;
};

class Window {
 public:
  Window() {}
  Window(int width, int height) : resolution_(width, height) {}
  explicit Window(const Resolution& resolution) : resolution_(resolution) {}

 private:
  Resolution resolution_;
};

}  // namespace rt

#endif
