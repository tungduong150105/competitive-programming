#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, x; std::cin >> n >> x;
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) std::cin >> c[i];
    constexpr int inf = 1000000005;
    std::vector<int> dp(x + 1, inf);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + c[i] <= x; ++j) dp[j + c[i]] = std::min(dp[j + c[i]], dp[j] + 1);
    }
    if (dp[x] == inf) dp[x] = -1;
    std::cout << dp[x] << "\n";
    return 0;
}
