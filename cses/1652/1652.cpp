#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n, q; std::cin >> n >> q;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> s[i];
    }
    std::vector a(n, std::vector<int> (n, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        a[i][j] = (s[i][j] == '*' ? 1 : 0);
        if (i) {
          a[i][j] += a[i - 1][j];
        }
        if (j) {
          a[i][j] += a[i][j - 1];
        }
        if (i && j) {
          a[i][j] -= a[i - 1][j - 1];
        }
      }
    }
    auto sum = [&](int x1, int y1, int x2, int y2) {
      int res = a[x2][y2];
      if (x1) {
        res -= a[x1 - 1][y2];
      }
      if (y1) {
        res -= a[x2][y1 - 1];
      }
      if (x1 && y1) {
        res += a[x1 - 1][y1 - 1];
      }
      return res;
    };
    for (int i = 0; i < q; ++i) {
      int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;
      --x1; --y1; --x2; --y2;
      std::cout << sum(x1, y1, x2, y2) << "\n";
    }
  }

  return 0;
}
