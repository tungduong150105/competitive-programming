#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T = 1;
  std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n; std::cin >> n;
    std::vector<int> ans;
    for (int i = n; i > 0; --i) {
      ans.push_back(i);
    }
    ans.push_back(n);
    for (int i = 1; i < n; ++i) {
      ans.push_back(i);
    }
    for (int i = 0; i < 2 * n; ++i) {
      std::cout << ans[i] << " \n"[i == 2 * n - 1];
    }
  }

  return 0;
}

// 5 4 3 2 1 5 1 2 3 4