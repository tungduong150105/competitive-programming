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
    int ans = n;
    int cnt = 0;
    int miss = -1;
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      if (!a[i]) {
        ++cnt;
        miss = i + 1;
      }
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (a[i] == miss) {
        ok = false;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (a[i] == i + 1 || (!a[i] && cnt == 1 && ok)) {
        --ans;
      } else {
        for (int j = n - 1; j > i; --j) {
          if (a[j] == j + 1 || (!a[j] && cnt == 1 && ok)) {
            --ans;
          } else {
            break;
          }
        }
        break;
      }
    }
    std::cout << ans << "\n";
  }

  return 0;
}
