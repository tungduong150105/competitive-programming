#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T; std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n; std::cin >> n;
    std::string s; std::cin >> s;

    int c = std::count(s.begin(), s.end(), '1');
    int ans = c;
    for (int i = n - 1; i >= n - c; --i) {
      if (s[i] == '1') {
        --ans;
      }
    }

    std::cout << ans << "\n";
  }

  return 0;
}
