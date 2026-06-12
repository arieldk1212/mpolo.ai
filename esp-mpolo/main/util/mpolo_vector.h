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
      : pool_(buffer_.data(), buffer_.size() * sizeof(T),
              std::pmr::null_memory_resource()),
        data_(&pool_) {}

  [[nodiscard]] PVector& Get() { return data_; }
  [[nodiscard]] std::size_t Size() const { return data_.size(); }

 private:
  std::array<T, S> buffer_;
  std::pmr::monotonic_buffer_resource pool_;
  PVector data_;
};

}  // namespace rt::util

#endif
