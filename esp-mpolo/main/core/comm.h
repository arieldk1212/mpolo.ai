#ifndef COMM_H_
#define COMM_H_

namespace rt::core {

class Communication {
 public:
  virtual ~Communication() = default;

  virtual void Read() = 0;
  virtual void Send() = 0;
};

}  // namespace rt::core

#endif
