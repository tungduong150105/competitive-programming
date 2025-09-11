#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T; std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n; std::cin >> n;

    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> p[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int left = 0, right = 0;
      for (int j = 0; j < i; ++j) {
        left += p[j] > p[i];
      }
      for (int j = i + 1; j < n; ++j) {
        right += p[j] > p[i];
      }
      ans += std::min(left, right);
    }

    std::cout << ans << "\n";
  }

  return 0;
}
