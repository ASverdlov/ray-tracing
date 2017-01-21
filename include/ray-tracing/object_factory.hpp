#ifndef OBJECT_FACTORY_HPP
#define OBJECT_FACTORY_HPP

#include "ray-tracing/object.hpp"

#include <string>
#include <vector>

namespace rt {

class ObjectFactory {
 public:
	template<typename Object>
	static Object* Create(const std::string& id) {
  	auto object = std::make_unique<Object>();
  	auto insertion_result = object_map.emplace(id, std::move(object));

  	auto* pointer_to_object = insertion_result.first->second.get();
  	bool was_inserted = insertion_result.second;
  	return was_inserted ? static_cast<Object*>(pointer_to_object) : nullptr;
  }

  static bool Remove(const std::string& id) {
    return object_map.erase(id) > 0;
  }

 private:
	ObjectFactory();

	using ObjectMap = std::unordered_map<std::string, std::unique_ptr<Object>>;
	static ObjectMap object_map;
};

}  // namespace rt

#endif
