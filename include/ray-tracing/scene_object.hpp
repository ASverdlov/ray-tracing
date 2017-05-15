#ifndef SCENE_OBJECT_HPP
#define SCENE_OBJECT_HPP

namespace rt {

/* Represents any object on scene.
 * Currently only: Triangle, Sphere, Light. */
class ISceneObject {
 public:
   virtual ~ISceneObject() {};
};

}  // namespace rt

#endif
