#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T; std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n, m; std::cin >> n >> m;

    int k; std::cin >> k;
    std::vector<int> c(k);
    for (int i = 0; i < k; ++i) {
      std::cin >> c[i];
    }

    if (m == 1) {
      std::cout << 1 << "\n";
    } else {
      std::vector dp(n, std::vector<int> (1 << n, 0));
      for (int i = 0; i < n; ++i) {
        for (int mask = 0; mask < (1 << n); ++mask) {
          dp[i][mask] = i % 2 == 0 ? 0 : 10;
        }
      }

      dp[n - 1][0] = 1;
      dp[n - 1][1] = 2;
      for (int i = n - 2; i >= 0; --i) {
        for (int mask = 0; mask < (1 << n); ++mask) {
          int num = n - i;
          if ((mask >> num) > 0) {
            continue;
          }
          for (int j = 0; j < k; ++j) {
            int shift = c[j];
            if (shift > num) {
              continue;
            }
            int new_mask = 0;
            for (int l = 0; l < shift - 1; ++l) {
              new_mask |= (mask >> l & 1) << l;
            }
            for (int l = shift; l < n; ++l) {
              new_mask |= (mask >> l & 1) << (l - 1);
            }
            // if (num == 3 && mask == 4) {
            //   std::cout << new_mask << "gg\n";
            // }
            if (dp[i + 1][new_mask]) {
              if (i % 2 == 0) {
                dp[i][mask] = std::max(dp[i][mask], dp[i + 1][new_mask]);
              } else {
                dp[i][mask] = std::min(dp[i][mask], dp[i + 1][new_mask]);
              }
            }
          }
        }
      }

      int ans = 0;
      for (int mask = 0; mask < (1 << n); ++mask) {
        ans += dp[0][mask];
        // for (int j = 0; j < 3; ++j) {
        //   std::cout << (mask >> j & 1);
        // }
        // std::cout << " ";
        // std::cout << dp[0][mask] << "\n";
      }

      std::cout << ans << "\n";
    }
  }

  return 0;
}
