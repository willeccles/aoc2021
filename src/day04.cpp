#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using Board = std::array<std::array<std::uint8_t, 5>, 5>;

constexpr inline void mark(std::uint8_t& x) { x |= 0x80; }

constexpr inline bool marked(const std::uint8_t& x) { return x & 0x80; }

constexpr inline bool check(const Board& board) {
  for (int i = 0; i < 5; ++i) {
    if (std::all_of(board[i].begin(), board[i].end(), marked)) {
      return true;
    }

    if (std::all_of(board.begin(), board.end(),
                    [&i](auto& b) { return marked(b[i]); })) {
      return true;
    }
  }

  return false;
}

constexpr inline unsigned score(const Board& board, const std::uint8_t& val) {
  unsigned score = 0;
  for (auto&& r : board) {
    for (auto&& v : r) {
      if (!marked(v)) {
        score += v;
      }
    }
  }

  return score * val;
}

int main(void) {
  std::string l;
  std::vector<std::uint8_t> draws;

  std::getline(std::cin, l);
  std::istringstream iss(l);
  int val;
  while (iss >> val) {
    draws.push_back(val);
    iss.ignore(1);
  }

  std::vector<Board> boards;
  Board tmp;
  while (std::cin) {
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        std::cin >> val;
        tmp[i][j] = val;
      }
    }
    boards.push_back(tmp);
  }

  unsigned firstscore = 0;
  unsigned lastscore = 0;
  for (const auto& draw : draws) {
    if (!boards.size()) {
      break;
    }

    for (std::size_t x = 0; x < boards.size(); ++x) {
      for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
          if (boards[x][i][j] == draw) {
            mark(boards[x][i][j]);
          }
        }
      }

      if (check(boards[x])) {
        if (firstscore == 0) {
          firstscore = score(boards[x], draw);
        } else {
          lastscore = score(boards[x], draw);
        }
        boards.erase(boards.begin() + x);
        --x;
      }
    }
  }

  std::cout
      << "Part 1: " << firstscore << '\n'
      << "Part 2: " << lastscore << '\n';

  return 0;
}
