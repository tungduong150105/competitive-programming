#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T; std::cin >> T;
  std::vector<int> cnt(200005, 0);
  for (int case_num = 0; case_num < T; ++case_num) {
    for (int i = 1; i < 200005; ++i) {
      cnt[i] = 0;
    }
    int n, y; std::cin >> n >> y;
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> c[i];
      ++cnt[c[i]];
    }
    for (int i = 1; i < 200005; ++i) {
      cnt[i] += cnt[i - 1];
    }
    int64_t ans = -1E18;
    for (int x = 2; x < 200005; ++x) {
      int64_t res = 0;
      for (int L = 0, v = 1; L < 200005; L += x, ++v) {
        int mx = std::min(L + x, 200000);
        int c = cnt[mx] - cnt[L];
        res += 1LL * c * v;
        if (c > cnt[v] - cnt[v - 1]) {
          res -= 1LL * y * (c - (cnt[v] - cnt[v - 1]));
        }
      }
      ans = std::max(ans, res);
    }
    std::cout << ans << "\n";
  }

  return 0;
}
