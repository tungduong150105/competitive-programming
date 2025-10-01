#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> a(3);
    for (int i = 0; i < 3; ++i) std::cin >> a[i];
    constexpr int inf = 1000000005;
    std::vector<int> dp(n + 1, -inf);
    dp[0] = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j + a[i] <= n; ++j) dp[j + a[i]] = std::max(dp[j + a[i]], dp[j] + 1);
    }
    std::cout << dp[n] << "\n";
    return 0;
}
