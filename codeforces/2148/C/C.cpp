#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  for (int case_num = 0; case_num < T; ++case_num) {
    int n, m;
    std::cin >> n >> m;

    int ans = 0;
    int cur = 0, prev = 0;

    for (int i = 0; i < n; ++i) {
      int a, b;
      std::cin >> a >> b;

      if ((a - cur) % 2 == (b - prev + 2) % 2) {
        ans += (a - cur);
      } else {
        ans += (a - cur - 1);
      }

      cur = a;
      prev = b;
    }

    ans += (m - cur);

    std::cout << ans << "\n";
  }

  return 0;
}
