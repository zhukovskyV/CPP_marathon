#include "countUniqueWords.h"

void valid_file(std::ifstream& file) {
    while (file.peek() == ' ')
        file.ignore(1);
    if (!file || file.peek() == EOF) {
        std::cerr << "error" << std::endl;
        exit(1);
    }
}

void uniqueWords(char** av) {
    std::multiset<std::string> words;
    std::string tmp;
    std::ifstream file(av[1]);
    std::regex wordRegex("[A-Za-z0-9'-]+");

    valid_file(file);
    while (getline(file, tmp)) {
        for (std::sregex_iterator it = std::sregex_iterator(tmp.begin(), tmp.end(), wordRegex)
                ; it != std::sregex_iterator(); it++) {
            std::string result = std::smatch(*it).str();
            words.insert(result);
        }
    }

    std::string name = newNameFile(av[1]);
    std::ofstream out(name);

    std::string str;
    for (const auto & item : words) {
        if (str != item)
            out << item << ": " << words.count(item) << std::endl;
        str = item;
    }
}


