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

    auto ask2 = [&](int left, int right) -> void {
      std::vector<int> values;
      for (int i = 0; i < (right - left + 1); ++i) {
        values.push_back(left + i);
        values.push_back(close);
        for (int j = 1; j < (1 << i); ++j) {
          values.push_back(open);
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

    std::vector<int> fx = {1, 3, 10, 36, 136, 528, 2080, 8256};

    std::string ans = "";
    for (int i = 1; i <= n; i += 8) {
      int mx = std::min(i + 7, n);
      ask2(i, mx);
      int v = get();
      int base = 0;
      for (int j = 0; j < (mx - i + 1); ++j) {
        base += fx[j];
      }
      for (int j = 0; j < (mx - i + 1); ++j) {
        if ((base - v) >> j & 1) {
          ans += ")";
        } else {
          ans += "(";
        }
      }
    }

    std::cout << "! " << ans << std::endl;
  }

  return 0;
}
