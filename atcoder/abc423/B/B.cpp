#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    int l = 0, r = n - 1;
    for (int i = 0; i < n; ++i) {
      if (!a[i]) {
        ++l;
      } else {
        break;
      }
    }
    for (int i = n - 1; i >= 0; --i) {
      if (!a[i]) {
        --r;
      } else {
        break;
      }
    }
    std::cout << std::max(0, r - l) << "\n";
  }

  return 0;
}
