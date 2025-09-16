#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  for (int case_num = 0; case_num < T; ++case_num) {
    int n;
    std::cin >> n;
    int64_t sum_e = 0;
    std::deque<int> a;

    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;

      if (x % 2) {
        a.push_back(x);
      } else {
        sum_e += x;
      }
    }

    std::sort(a.begin(), a.end());
    int64_t ans = 0;

    if (a.size()) {
      ans += sum_e + a.back();
      a.pop_back();
    }

    while (a.size()) {
      a.pop_front();

      if (a.size()) {
        ans += a.back();
        a.pop_back();
      }
    }

    std::cout << ans << "\n";
  }

  return 0;
}
