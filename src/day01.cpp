#include <iostream>

// This is gross.

int main(void) {
  int vals[3];
  int idx = 0;
  int psum = 0;
  int pval = 0;
  int count1 = 0;
  int count2 = 0;

  std::cin >> vals[0] >> vals[1] >> vals[2];

  // Preprocess the first 3 values for part 1
  pval = vals[0];
  for (int i = 1; i < 3; ++i) {
    if (vals[i] > pval) {
      ++count1;
    }
    pval = vals[i];
  }

  // Preprocess the first 3 values for part 2
  psum = vals[0] + vals[1] + vals[2];

  while (std::cin >> vals[idx]) {
    // Part 1
    if (vals[idx] > pval) {
      ++count1;
    }
    pval = vals[idx];

    // Part 2
    int sum = vals[0] + vals[1] + vals[2];
    if (sum > psum) {
      ++count2;
    }
    psum = sum;
    idx = (idx + 1) % 3;
  }

  std::cout
      << "part 1: " << count1 << '\n'
      << "part 2: " << count2 << '\n';

  return 0;
}
