#ifndef COMPONENT_H_
#define COMPONENT_H_

namespace rt::components {

class Component {
 public:
  virtual ~Component() = default;

  virtual void SetCallback() = 0;
  virtual void SetPressedCallback() {}
  virtual void SetReleasedCallback() {}
};

}  // namespace rt::components

#endif
