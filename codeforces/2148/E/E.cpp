#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  for (int case_num = 0; case_num < T; ++case_num) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    std::vector<int> cnt(n + 1, 0);

    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      ++cnt[a[i]];
    }

    bool ok = true;

    for (int i = 1; i <= n; ++i) {
      if (cnt[i] % k) {
        ok = false;
      }

      cnt[i] /= k;
    }

    if (ok) {
      std::vector<int> c(n + 1, 0);

      int64_t ans = 0;

      for (int r = 0, l = 0; r < n; ++r) {
        ++c[a[r]];

        if (c[a[r]] > cnt[a[r]]) {
          while (c[a[r]] > cnt[a[r]]) {
            --c[a[l++]];
          }
        }

        ans += r - l + 1;
      }

      std::cout << ans << "\n";
    } else {
      std::cout << "0\n";
    }
  }

  return 0;
}
