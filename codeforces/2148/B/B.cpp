#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  for (int case_num = 0; case_num < T; ++case_num) {
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;

    std::vector<int> a(n);

    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }

    std::vector<int> b(n);

    for (int i = 0; i < m; ++i) {
      std::cin >> b[i];
    }

    std::cout << n + m << "\n";
  }

  return 0;
}
