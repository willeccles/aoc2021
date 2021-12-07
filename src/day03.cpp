#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <vector>

int main(void) {
  std::array<int, 12> ones;
  std::array<int, 12> zeroes;
  ones.fill(0);
  zeroes.fill(0);

  std::vector<std::bitset<12>> vals;
  std::bitset<12> val;

  while (std::cin >> val) {
    for (int i = 0; i < 12; ++i) {
      ++((val[i] ? ones : zeroes)[i]);
    }
    vals.push_back(val);
  }

  std::bitset<12> gamma, epsilon;

  for (int i = 0; i < 12; ++i) {
    gamma[i] = (ones[i] > zeroes[i]);
  }

  epsilon = ~gamma;

  std::cout << "part 1: " << gamma.to_ulong() * epsilon.to_ulong() << '\n';

  // This is a hideous solution, but I don't really care as long as it works.
  // This is just AOC, after all.

  auto begin = vals.begin();
  auto end = vals.end();
  for (int i = 12-1; std::distance(begin, end) > 1 && i >= 0; --i) {
    auto it = std::partition(begin, end, [&](auto& v) { return v[i]; });
    if (std::distance(begin, it) >= std::distance(it, end)) {
      end = it;
    } else {
      begin = it;
    }
  }
  auto o2 = *begin;

  begin = vals.begin();
  end = vals.end();
  for (int i = 12-1; std::distance(begin, end) > 1 && i >= 0; --i) {
    auto it = std::partition(begin, end, [&](auto& v) { return !v[i]; });
    if (std::distance(begin, it) <= std::distance(it, end)) {
      end = it;
    } else {
      begin = it;
    }
  }
  auto co2 = *begin;

  std::cout << "part 2: " << o2.to_ulong() * co2.to_ulong() << '\n';

  return 0;
}
