#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int x, c;
    std::cin >> x >> c;
    int ans = 0;
    for (int i = 1000; i <= x; i += 1000) {
      int g = i / 1000;
      if (i + g * c <= x) {
        ans = i;
      }
    }
    std::cout << ans << "\n";
  }

  return 0;
}
