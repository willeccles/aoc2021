#include <iostream>
#include <string>

int main(void) {
  int pos = 0;
  int depth1 = 0;
  int depth2 = 0;
  int aim = 0;

  std::string cmd;
  int arg;

  while (std::cin >> cmd >> arg) {
    if (cmd == "up") {
      depth1 -= arg;
      aim -= arg;
    } else if (cmd == "down") {
      depth1 += arg;
      aim += arg;
    } else if (cmd == "forward") {
      pos += arg;
      depth2 += aim * arg;
    }
  }

  std::cout
      << "part 1: " << pos * depth1 << '\n'
      << "part 2: " << pos * depth2 << '\n';

  return 0;
}
