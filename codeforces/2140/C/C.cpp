#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T; std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n; std::cin >> n;

    int64_t ans = 0;
    int64_t ml0 = -1E17, ml1 = -1E17;
    int64_t mx = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      if (i % 2 == 0) {
        ans += a[i];
        mx = std::max(mx, -2LL * a[i] + (i + 1) + ml1);
        mx = std::max(mx, i - 0LL);
        ml0 = std::max(ml0, -2LL * a[i] - (i + 1));
      } else {
        ans -= a[i];
        mx = std::max(mx, 2LL * a[i] + (i + 1) + ml0);
        mx = std::max(mx, i - 1LL);
        ml1 = std::max(ml1, 2LL * a[i] - (i + 1));
      }
    }

    std::cout << ans + mx << "\n";
  }

  return 0;
}
