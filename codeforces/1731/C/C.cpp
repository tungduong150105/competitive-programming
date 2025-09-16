#include "bits/stdc++.h"

using ll = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n;
    std::cin >> n;

    int mx = sqrt(2 * n) + 1;
    ll ans = 1LL * n * (n + 1) / 2;
    std::vector<int> a(n);
    std::vector<int> f(2 * n, 0);
    f[0] = 1;
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      if (i > 0) {
        a[i] ^= a[i - 1];
      }
      for (int j = 0; j < mx; ++j) {
        int g = a[i] ^ (j * j);
        if (g < 2 * n) {
          ans -= f[g];
        }
      }
      ++f[a[i]];
    }

    std::cout << ans << "\n";
  }

  return 0;
}
