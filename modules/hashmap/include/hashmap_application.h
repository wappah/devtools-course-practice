// Copyright 2020 Nazarov Vladislav

#ifndef MODULES_HASHMAP_INCLUDE_HASHMAP_APPLICATION_H_
#define MODULES_HASHMAP_INCLUDE_HASHMAP_APPLICATION_H_

#include <string>
#include "include/hashmap.h"

class hashmapApp {
 public:
    hashmapApp() = default;
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);

    hashmap<int, int> _hashmap;
    std::string _message;
};

#endif  // MODULES_HASHMAP_INCLUDE_HASHMAP_APPLICATION_H_ 