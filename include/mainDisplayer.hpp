#ifndef MAIN_DISPLAYER_HPP
#define MAIN_DISPLAYER_HPP

namespace disp {

class MainDisplayer : public Displayer {
public:
    void display();

private:
    shared_ptr<Scene> scene;
};

} // namespace disp

#endif
