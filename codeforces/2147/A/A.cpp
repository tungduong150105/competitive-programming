#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T = 1;
  std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int x, y; std::cin >> x >> y;
    if (x < y) {
      std::cout << "2\n";
    } else if (x - 1 > y && y > 1) {
      std::cout << "3\n";
    } else {
      std::cout << "-1\n";
    }
  }

  return 0;
}
