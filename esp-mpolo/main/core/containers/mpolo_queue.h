#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <cstddef>

namespace rt::core::containers {

static constexpr int kQueueSize{100};

template <typename T, std::size_t S = kQueueSize>
class MpoloQueue {};

}  // namespace rt::core::containers

#endif
