#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  for (int case_num = 0; case_num < T; ++case_num) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n);

    for (int i = 0; i < n; ++i) {
      int k;
      std::cin >> k;

      for (int j = 0; j < k; ++j) {
        int x;
        std::cin >> x;
        a[i].push_back(x);
      }
    }

    std::vector<int> ans;

    while (a.size()) {
      std::sort(a.begin(), a.end());
      int len = int(a[0].size());

      for (int i = 0; i < len; ++i) {
        ans.push_back(a[0][i]);
      }

      std::vector<std::vector<int>> new_a;

      for (auto v : a) {
        if (int(v.size()) <= len) {
          continue;
        }
        std::vector<int> b;

        for (int j = len; j < int(v.size()); ++j) {
          b.push_back(v[j]);
        }
        new_a.push_back(b);
      }
      std::swap(a, new_a);
    }
    for (int i = 0; i < int(ans.size()); ++i) {
      std::cout << ans[i] << " \n"[i == int(ans.size()) - 1];
    }
  }

  return 0;
}
