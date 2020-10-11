#pragma once

#include <atomic>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <future>

class Worker {
 public:
  Worker() = default;
  ~Worker() = default;
  template <typename Function, class... Args>
  auto startAsync(Function && func, Args && ... args) {
    return std::async(func, args...);
  }
};