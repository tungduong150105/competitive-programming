#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> h(n);
    for (int i = 0; i < n; ++i) std::cin >> h[i];
    constexpr int inf = 1000000005;
    std::vector<int> dp(n, inf);
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        dp[i] = std::min(dp[i], dp[i - 1] + std::abs(h[i] - h[i - 1]));
        if (i >= 2) dp[i] = std::min(dp[i], dp[i - 2] + std::abs(h[i] - h[i - 2]));
    }
    std::cout << dp[n - 1] << "\n";
    return 0;
}
