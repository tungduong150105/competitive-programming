#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T; std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n; std::cin >> n;

    auto ask = [&](int left, int right) -> void {
      std::cout << "? " << right - left << " ";
      for (int i = left; i < right; ++i) {
        std::cout << i << " ";
      }
      std::cout << std::endl;
    };

    auto get = [&]() -> int {
      int k; std::cin >> k;
      return k;
    };

    int open = -1, close = -1;
    int l = 2, r = n + 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      ask(1, m);
      if (get() > 0) {
        r = m;
      } else {
        l = m;
      }
    }

    ask(1, r);
    if (get() > 0) {
      open = r - 2;
      close = r - 1;
    } else {
      open = n;
      close = 1;
    }

    std::vector<int> fx = {1, 2, 3, 5, 7, 10, 15, 21, 30, 43, 61, 87};
    std::vector<int> fy = {1, 3, 6, 15, 28, 55, 120, 231, 465, 946, 1891, 3828};
    std::reverse(fx.begin(), fx.end());
    std::reverse(fy.begin(), fy.end());
    auto ask2 = [&](int left, int right) -> void {
      std::vector<int> values;
      for (int i = 0; i < (right - left + 1); ++i) {
        for (int j = 0; j < fx[i]; ++j) {
          values.push_back(left + i);
          values.push_back(close);
        }
        values.push_back(close);
      }
      std::cout << "? " << (int) values.size() << " ";
      for (int v : values) {
        std::cout << v << " ";
      }
      std::cout << std::endl;
    };

    std::string ans = "";
    for (int i = 1; i <= n; i += 12) {
      int mx = std::min(i + 11, n);
      ask2(i, mx);
      int v = get();
      for (int j = 0; j < (mx - i + 1); ++j) {
        if (v >= fy[j]) {
          v -= fy[j];
          ans += "(";
        } else {
          ans += ")";
        }
      }
      assert(v == 0);
    }

    std::cout << "! " << ans << std::endl;
  }

  return 0;
}
