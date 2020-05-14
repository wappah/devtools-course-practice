// Copyright 2020 Mazur Daniil
#ifndef MODULES_CIESARS_CODE_INCLUDE_CIESARS_CODE_APPLICATION_H_
#define MODULES_CIESARS_CODE_INCLUDE_CIESARS_CODE_APPLICATION_H_

#include <string>
#include <iostream>
#include <fstream>
#include "include/ciesars_code.h"

class CiesarsCodeApplication {
 protected:
  bool readFile(std::string in_filename);
  void writeFile(std::string out_filename);
  std::string filetext_;
  CiesarsCode code_;

 public:
  std::string operator()(int argc, const char** argv);
  std::string getHelpMessage();
  std::string decodeFile(std::string in_filename, std::string out_filename,
                         int key);
  std::string encodeFile(std::string in_filename, std::string out_filename,
                         int key);
};

#endif  // MODULES_CIESARS_CODE_INCLUDE_CIESARS_CODE_APPLICATION_H_
