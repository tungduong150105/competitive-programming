#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      if (i) {
        a[i] += a[i - 1];
      }
    }
    int l = 0, r = 0;
    for (int i = 0; i < n - 2; ++i) {
      for (int j = i + 1; j < n - 1; ++j) {
        int x = a[i];
        int y = a[j] - a[i];
        int z = a[n - 1] - a[j];
        std::set<int> g;
        g.insert(x % 3);
        g.insert(y % 3);
        g.insert(z % 3);
        if (int(g.size()) == 3 || int(g.size()) == 1) {
          l = i + 1;
          r = j + 1;
        }
      }
    }
    std::cout << l << " " << r << "\n";
  }

  return 0;
}
