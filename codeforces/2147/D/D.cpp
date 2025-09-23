#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T = 1;
  std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n; std::cin >> n;
    std::vector<int> a(n);
    std::map<int, int> cnt;
    std::set<int> ms;
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      ++cnt[a[i]];
      ms.insert(a[i]);
    }
    ms.insert(0);
    std::set<std::tuple<int, int, int>> s;
    for (auto [x, v] : cnt) {
      s.insert(std::make_tuple(0, -v, x));
    }
    int t = 0;
    int64_t ans0 = 0, ans1 = 0;
    for (auto [g, v, x] : s) {
      ans0 += 1LL * -v * (x / 2);
      ans1 += 1LL * -v * (x / 2);
      if (x % 2) {
        if (!t) {
          ans0 += -v;
        } else {
          ans1 += -v;
        }
        t ^= 1;
        }
    }
    std::cout << ans0 << " " << ans1 << "\n";
  }

  return 0;
}
