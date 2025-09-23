#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T = 1;
  std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        std::vector<int> g(2, 0);
        g[1] = 1;
        g[0] = (i ? 0 : 1);
        for (int j = i + 1; j < n; ++j) {
          std::vector<int> ng(2, 0);
          if (s[j] == '0' && s[j - 1] == '0') {
            ng[0] = 1;
            ng[1] = 1;
          }
          if (s[j] == '1') {
            if (j == n - 1) {
              if (!g[0]) {
                ok = false;
                break;
              }
            } else {
              continue;
            }
          }
          if (s[j] == '0' && s[j - 1] == '1') {
            if (s[j - 2] == '0') {
              ng[0] |= g[1];
              ng[1] |= g[0];
            } else {
              ng[1] |= g[0];
            }
          }
          if (s[j] == '0' && ng[0] == 0 && ng[1] == 0) {
            ok = false;
            break;
          }
          std::swap(g, ng);
        }
        break;
      }
    }
    std::cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
