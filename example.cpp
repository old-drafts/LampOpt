/*
This project was under the GPL-2.0 License.
Copyright(c) 2022 Lampese.
Copyright(c) 2022 nu11ptr.
*/
#include <iostream>
#include <map>
#include <vector>

#include "./opt.h"

int main(int argc, char** argv) {
  std::vector<std::string> args(argc - 1);
  std::map<std::string, std::string> alias;  // aliases
  alias["--help"] = "-h";
  for (size_t i = 1; i < argc; i++) args[i - 1] = std::string(argv[i]);
  LampOpt::Arguments arg(args, alias);
  if (arg.args.empty()) {
    std::cout << "no arguments given" << std::endl;
    return 1;
  }
  if (arg.args.find("-h") == arg.args.cend()) {
    std::cout << "unsupported arguments" << std::endl;
    return 1;
  }
  std::cout << "LampOpt test v0.01" << std::endl;
  std::cout << "Usage:" << std::endl;
  std::cout << "-h,--help : display this help message." << std::endl;
  std::cout << "This project was under the GPL-2.0 License." << std::endl;
  std::cout << "Copyright(c) 2022 Lampese." << std::endl;
  std::cout << "Copyright(c) 2022 nu11ptr." << std::endl;
  return 0;
}