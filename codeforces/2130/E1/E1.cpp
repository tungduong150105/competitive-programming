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
    
    std::string ans = "";
    for (int i = 1; i < n; i += 2) {
      std::cout << "? 6 " << i << " " << close << " " << open << " " << i + 1 << " " << open << " " << close << std::endl;
      int v; std::cin >> v;
      if (v == 2) {
        ans += "((";
      } else if (v == 6) {
        ans += "()";
      } else if (v == 3) {
        ans += "))";
      } else {
        ans += ")(";
      }
    }

    if (n % 2 == 1) {
      std::cout << "? 2 " << open << " " << n << std::endl;
      int v; std::cin >> v;
      if (v == 1) {
        ans += ")";
      } else {
        ans += "(";
      }
    }

    std::cout << "! " << ans << std::endl;
  }

  return 0;
}
