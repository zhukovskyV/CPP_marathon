#include "bookSaver.h"

bool oneWord(std::stringstream& streamCmd, std::string& var) {
    if (!(streamCmd >> var)) {
        std::cout << "invalid command" << std::endl;
        return false;
    }
    while (streamCmd.peek() == ' ')
        streamCmd.ignore(1);
    if (streamCmd.peek() != EOF) {
        std::cout << "invalid command" << std::endl;
        return false;
    }
    return true;
}

void quit() {
    std::cout << "bye" << std::endl;
    exit(0);
}

void listBooks(std::map<std::string,std::string>& lib) {
    std::map<std::string,std::string>::iterator it = lib.begin();

    for (; it != lib.end(); it++)
        std::cout << it->first << std::endl;
}

void addBook(std::stringstream& streamCmd, std::map<std::string,std::string>& lib) {
    std::string input;

    if (!(oneWord(streamCmd, input)))
        return ;

    std::string filename = "./library/" + input;
    std::ifstream file;
    file.open(filename);
    if (!file) {
        std::cout << "invalid book" << std::endl;
        return ;
    }
    std::stringstream ss;
    ss << file.rdbuf();

    std::string tmp = ss.str();

    std::pair<std::map<std::string,std::string>::iterator,bool> ret;

    ret = lib.insert(std::pair<std::string,std::string>(input, tmp));
    if (ret.second == false) {
        std::cout << "invalid book" << std::endl;
        return ;
    }
    std::cout << input << " added" << std::endl;
}

void deleteBook(std::stringstream& streamCmd, std::map<std::string,std::string>& lib) {
    std::string input;

    if (!(oneWord(streamCmd, input)))
        return ;

    std::map<std::string,std::string>::iterator it = lib.find(input);

    if (it != lib.end()) {
        lib.erase(it);
        std::cout << input << " deleted" << std::endl;
    } else {
        std::cout << "invalid book" << std::endl;
    }
}

void readBook(std::stringstream& streamCmd, std::map<std::string,std::string>& lib) {
    std::string input;

    if (!(oneWord(streamCmd, input)))
        return ;

    std::map<std::string,std::string>::iterator it = lib.find(input);

    if (it != lib.end()) {
        std::cout << it->second << std::endl;
        return ;
    }
    std::cout << "invalid book" << std::endl;
}

void validCommand(std::stringstream& ss, std::map<std::string,std::string>& lib) {
    std::string input;
    std::getline(ss, input, ' ');
    if (input == "quit") {
        quit();
    } else if (input == "list") {
        listBooks(lib);
    } else if (input == "add") {
        addBook(ss, lib);
    } else if (input == "delete") {
        deleteBook(ss, lib);
    } else if (input == "read") {
        readBook(ss, lib);
    } else {
        std::cout << "invalid command" << std::endl;
    }
}
