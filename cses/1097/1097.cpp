#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> x(n);
    for (int i = 0; i < n; ++i) std::cin >> x[i];
    constexpr int64_t inf = int64_t(1E18);
    std::vector dp(n, std::vector<int64_t> (n, -inf));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            if (i == j) {
                dp[i][j] = 0;
                if (n & 1) dp[i][j] = x[i];
            } else {
                int turn = ((j - i + 1) & 1) ^ (n & 1);
                if (turn) dp[i][j] = std::min(dp[i + 1][j], dp[i][j - 1]);
                else dp[i][j] = std::max(dp[i + 1][j] + x[i], dp[i][j - 1] + x[j]);
            }
        }
    }
    std::cout << dp[0][n - 1] << "\n";
    return 0;
}
