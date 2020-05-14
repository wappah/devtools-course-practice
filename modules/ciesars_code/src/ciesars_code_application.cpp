// Copyright 2020 Mazur Daniil

#include "include/ciesars_code_application.h"
#include <string>

std::string CiesarsCodeApplication::operator()(int argc, const char** argv) {
  std::string result = "";
  std::string in_filename = "";
  std::string out_filename = "";
  std::string operation = "";

  if (argc > 4) {
    int key = 0;
    in_filename = argv[1];
    out_filename = argv[2];
    key = atoi(argv[3]);
    operation = argv[4];

    if (operation == "EN") {
      result = encodeFile(in_filename, out_filename, key);
    }

    if (operation == "DE") {
      result = decodeFile(in_filename, out_filename, key);
    }

    if (operation != "DE" && operation != "EN") {
      result = getHelpMessage();
    }

  } else {
    result = getHelpMessage();
  }

  if (result == "") {
    result = getHelpMessage();
  }

  return result;
}

std::string CiesarsCodeApplication::getHelpMessage() {
  std::string help_message;
  help_message =
      "\nThis application encodes/decodes the contents of the file.\n";
  help_message += "Please provide arguments in the following format:\n";
  help_message += "1: File name(string) for operation;\n";
  help_message += "2: File name(string) to save the result;\n";
  help_message += "3: The key(int) to encode/decode operations;\n";
  help_message += "4: The operation(string): EN to encode or DE to decode;\n";
  return help_message;
}

std::string CiesarsCodeApplication::decodeFile(std::string in_filename,
                                               std::string out_filename,
                                               int key) {
  filetext_ = "";
  if (readFile(in_filename)) {
    filetext_ = code_.decode(filetext_, key);
    writeFile(out_filename);
  }
  return filetext_;
}

std::string CiesarsCodeApplication::encodeFile(std::string in_filename,
                                               std::string out_filename,
                                               int key) {
  filetext_ = "";
  if (readFile(in_filename)) {
    filetext_ = code_.encode(filetext_, key);
    writeFile(out_filename);
  }
  return filetext_;
}

bool CiesarsCodeApplication::readFile(std::string in_filename) {
  std::ifstream in_file(in_filename);
  if (!in_file.is_open()) {
    return false;
  } else {
    filetext_.assign((std::istreambuf_iterator<char>(in_file.rdbuf())),
                    std::istreambuf_iterator<char>());
    in_file.close();
  }
  return true;
}

void CiesarsCodeApplication::writeFile(std::string out_filename) {
  std::ofstream out_file(out_filename);
  out_file << filetext_;
  out_file.close();
}
