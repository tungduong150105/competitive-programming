#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, h; std::cin >> n >> h;
    std::vector dp(n + 1, std::vector<int64_t> (n + 1, 0));
    for (int i = 0; i < n; ++i) dp[0][i] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            // l nodes on left and i - l - 1 nodes on right
            for (int l = 0; l < i; ++l) dp[i][j] += dp[l][j - 1] * dp[i - l - 1][j - 1];
        }
    }
    std::cout << dp[n][n] - dp[n][h - 1] << "\n";
    return 0;
}
