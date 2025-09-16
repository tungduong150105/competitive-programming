#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  std::vector<std::vector<int>> g(200005);
  for (int i = 2; i <= 200000; ++i) {
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        g[i].push_back(j);
        if (i / j != j) {
          g[i].push_back(i / j);
        }
      }
    }
  }

  for (int case_num = 0; case_num < T; ++case_num) {
    int n;
    std::cin >> n;
    std::vector<int> cnt(n + 1, 0);
    int ans = 0;

    int root = -1;

    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;

      if (root == -1) {
        root = x;
      }

      if (x != 1) {
        ++cnt[x];

        if (cnt[x] != i + 1) {
          ans = std::max(ans, cnt[x]);
        }
      }

      for (int j : g[x]) {
        ++cnt[j];

        if (cnt[j] != i + 1) {
          ans = std::max(ans, cnt[j]);
        }
      }

      for (int j : g[root]) {
        if (cnt[j] != i + 1) {
          ans = std::max(ans, cnt[j]);
        }
      }

      if (cnt[root] != i + 1) {
        ans = std::max(ans, cnt[root]);
      }

      std::cout << ans << " \n"[i == n - 1];
    }
  }

  return 0;
}

