#include "multithreadedfilehandler.h"

//static void foo() {
//  std::cout << "-----1 second sleep-----\n";
//  std::this_thread::sleep_for(std::chrono::milliseconds(300));
//}

int main(int ac, char **av) {
  if (ac != 3) {
    std::cerr << "usage: ./multithreadedFileHandler [file1] [file2]\n";
    return 1;
  }
  try {
    MultithreadedFileHandler obj;
    Worker worker;
    const std::string first = av[1];
    const std::string second = av[2];

    worker.startNewThread(&MultithreadedFileHandler::loadFile, &obj, first);
    // worker.startNewThread(&foo);

    worker.startNewThread(&MultithreadedFileHandler::loadFile, &obj, second);
    
    worker.startNewThread(&MultithreadedFileHandler::processFile, &obj);
    
    worker.startNewThread(&MultithreadedFileHandler::processFile, &obj);

    worker.joinAllThreads();

  } catch (...) {
    std::cerr << "error\n";
    return 1;
  }
}