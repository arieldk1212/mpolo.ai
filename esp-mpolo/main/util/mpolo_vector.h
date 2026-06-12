#ifndef MPOLO_VECTOR_H_
#define MPOLO_VECTOR_H_

#include <array>
#include <memory_resource>
#include <vector>

namespace rt::util {

static constexpr int kVectorSize{512};

template <typename T, std::size_t S = kVectorSize>
class MpoloVector {
 public:
  using PVector = std::pmr::vector<T>;

  MpoloVector()
      : data_(std::move(InitBuffer())) {}

  PVector& Get() { return data_; }
  [[nodiscard]] int Size() const { return data_.size(); }

 private:
  PVector InitBuffer() {
    std::array<T, S> buffer;
    std::pmr::monotonic_buffer_resource pool(&buffer, buffer.size(),
                                             std::pmr::null_memory_resource());
    PVector data(&buffer);
    return data;
  }

  PVector data_;
};

}  // namespace rt::util

#endif
