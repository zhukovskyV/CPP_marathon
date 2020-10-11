#pragma once

#include <fstream>
#include <mutex>
#include "worker.h"

class MultithreadedFileHandler {
 public:
  MultithreadedFileHandler() = default;
  ~MultithreadedFileHandler() = default;
  void processFile() {
    std::unique_lock<std::mutex> l(m_mutex);
    
    if(!m_fileLoaded)
      m_condVar.wait(l);
    std::cout << m_file;
    m_fileLoaded = false;
    std::cout << "-----1 second sleep-----\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
  }
  void loadFile(const std::string& fileName) {
    std::lock_guard<std::mutex> lg(m_mutex);
    std::ifstream file(fileName);
    std::string buf;

    m_file.erase();
    if (!file)
      throw 1;
    while (std::getline(file, buf))
      m_file += (buf + '\n');
    file.close();
    m_fileLoaded = true;
    m_mutex.unlock();
    m_condVar.notify_one();
  }

 private:
  std::string m_file;
  std::mutex m_mutex;
  std::condition_variable m_condVar;
  bool m_fileLoaded{false};
};