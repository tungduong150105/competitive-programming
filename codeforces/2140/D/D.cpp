#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T; std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n; std::cin >> n;
    
    int64_t ans = 0;
    int64_t add = 0;
    std::vector<std::pair<int64_t, int>> f;
    for (int i = 0; i < n; ++i) {
      int l, r; std::cin >> l >> r;
      ans += r - l;
      add += r;
      f.emplace_back(l + r, r);
    }

    std::sort(f.begin(), f.end());
    if (n % 2 == 0) {
      for (int i = 0; i < n / 2; ++i) {
        add -= f[i].first;
      }
    } else {
      for (int i = 0; i < n / 2; ++i) {
        add -= f[i].first;
      }
      int64_t mx = 0;
      for (int i = n / 2; i < n; ++i) {
        mx = std::max(mx, add - f[i].second);
      }
      for (int i = 0; i < n / 2; ++i) {
        mx = std::max(mx, add + f[i].first - f[i].second - f[n / 2].first);
      }
      add = mx;
    }

    std::cout << ans + add << "\n";
  }

  return 0;
}
