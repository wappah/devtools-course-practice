// Copyright 2020 Zinkov Artem

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/merge_batcher_app.h"

int main(int argc, const char** argv) {
    Merge_Batcher_App app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
