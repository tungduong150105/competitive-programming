#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T; std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n; std::cin >> n;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int a; std::cin >> a;
      ans += std::max(a, 1);
    }

    std::cout << ans << '\n';
  }

  return 0;
}
