#include "worker.h"
#include "classwithatomic.h"

static bool is_number(const std::string& s) {
  return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

static bool parse(char** av) {
  size_t idx = 0;
  int check;

  for (int i = 1; av[i]; i++) {
    if (!is_number(std::string(av[i])))
      return false;
    check = std::stoi(av[i], &idx);
    if (av[i][idx] != '\0')
      return false;
  }
  return true;
}

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "usage: classWithAtomic [add] [subtract] [size]\n";
    return 1;
  }
  if (!parse(argv)) {
    std::cerr << "Incorrect values\n";
    return 1;
  }
  int addValue = std::stoi(argv[1]);
  int subtractValue = std::stoi(argv[2]);
  int pushSize = std::stoi(argv[3]);
  //...
  Worker worker;
  ClassWithAtomic obj;
  worker.startNewThread(&ClassWithAtomic::addToInt, &obj, addValue);
  worker.startNewThread(&ClassWithAtomic::subtractFromInt, &obj, subtractValue);
  for (auto i = 0; i < pushSize; ++i) {
    worker.startNewThread(&ClassWithAtomic::pushToVector, &obj, i);
  }
  for (auto i = 1; i <= pushSize; ++i) {
    if (i % 2 == 0) {
      worker.startNewThread(&ClassWithAtomic::eraseFromVector, &obj, i);
    }
  }
  worker.joinAllThreads();
  std::cout << "Result: " << obj.getInt() << std::endl;
  auto vec = obj.getVector();
  std::cout << "Size of vector: " << vec.size() << std::endl;
  for (unsigned long i = 0; i < vec.size(); ++i) {
    std::cout << vec[i];
    if (i != vec.size() - 1) {
      std::cout << " ";
    } else {
      std::cout << std::endl;
    }
  }
}
