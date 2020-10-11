#pragma once

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

class Worker {
 public:
  Worker() = default;
  ~Worker() {
    joinAllThreads();
  }
  template <typename Function, class... Args>
  void startNewThread(Function&& func, Args&&... args) {
    m_workerThreads.push_back(std::thread(func, (std::forward<Args>(args))...));
  }
  void joinAllThreads() {
    for (auto &it : m_workerThreads)
      if (it.joinable())
        it.join();
  }

 private:
  std::vector<std::thread> m_workerThreads;
};