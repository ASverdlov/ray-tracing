#ifndef OBJECT_MANAGER_HPP
#define OBJECT_MANAGER_HPP

#include "ray-tracing/macroses.hpp"
#include "ray-tracing/scene_object.hpp"

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <utility>

namespace rt {

class SceneObjectManager {
 public:
  template<typename T>
  static T* Create(const std::string& id) {
    auto created_object_ptr = std::make_unique<T>();
    auto insertion_info = objects_.emplace(id, std::move(created_object_ptr));

    bool successful_insertion = insertion_info.second;
    auto* inserted_object_ptr = insertion_info.first->second.get();

    if (successful_insertion)
      return static_cast<T*>(inserted_object_ptr);
    else
      return nullptr;
  }

  static ISceneObject* Get(const std::string& id) {
    if (objects_.count(id))
      return objects_[id].get();
    else
      return nullptr;
  }

  static bool Remove(const std::string& id) {
    return objects_.erase(id) > 0;
  }

 private:
  using Id2Object = std::unordered_map<std::string, std::unique_ptr<ISceneObject>>;

 private:
  DISABLE_COPYING(SceneObjectManager);

  static Id2Object objects_;
};

}  // namespace rt

#endif
