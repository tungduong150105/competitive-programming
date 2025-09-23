#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n, r;
    std::cin >> n >> r;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    int L = 0, R = n - 1;
    while (L < n && a[L]) {
      ++L;
    }
    while (R >= 0 && a[R]) {
      --R;
    }
    int ans = 0;
    for (int i = r - 1; i >= L; --i) {
      ans += a[i] + 1;
    }
    for (int i = r; i <= R; ++i) {
      ans += a[i] + 1;
    }
    std::cout << ans << "\n";
  }

  return 0;
}
