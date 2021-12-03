#include <iostream>

int main(void) {
  int prev, val;
  int inc = 0;
  std::cin >> prev;
  while (std::cin >> val) {
    if (val > prev) {
      ++inc;
    }
    prev = val;
  }
  std::cout << "part 1: " << inc << '\n';
  return 0;
}
