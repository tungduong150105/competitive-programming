#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  for (int case_num = 0; case_num < T; ++case_num) {
    int x, n;
    std::cin >> x >> n;

    if (n % 2 == 0) {
      x = 0;
    }

    std::cout << x << "\n";
  }

  return 0;
}
