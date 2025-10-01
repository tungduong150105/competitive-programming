#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
    std::vector<int> factor(60);
    for (int i = 2; i < 60; ++i) {
        int mask = 0;
        for (int j = 0; j < 17; ++j) {
            if (i % primes[j] == 0) mask |= (1 << j);
        }
        factor[i] = mask;
    }
    constexpr int inf = int(1E9);
    std::vector dp(n, std::vector<int> (1 << 17, inf));
    std::vector prev(n, std::vector<int> (1 << 17, -1));
    for (int i = 1; i < 59; ++i) {
        auto &value = dp[0][factor[i]];
        if (value > std::abs(i - a[0])) {
            value = std::abs(i - a[0]);
            prev[0][factor[i]] = i;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int mask = 0; mask < (1 << 17); ++mask) {
            for (int v = 1; v < 59; ++v) {
                if (!(mask & factor[v])) {
                    auto &value = dp[i][mask | factor[v]];
                    if (value > dp[i - 1][mask] + std::abs(v - a[i])) {
                        value = dp[i - 1][mask] + std::abs(v - a[i]);
                        prev[i][mask | factor[v]] = v;
                    }
                }
            }
        }
    }
    // std::cout << *std::min_element(dp[n - 1].begin(), dp[n - 1].end()) << "\n";
    int min_mask = int(std::distance(dp[n - 1].begin(), std::min_element(dp[n - 1].begin(), dp[n - 1].end())));
    std::vector<int> path;
    while (int(path.size()) < n) {
        int v = prev[n - 1 - int(path.size())][min_mask];
        path.push_back(v);
        min_mask ^= factor[v];
    }
    std::reverse(path.begin(), path.end());
    for (int i = 0; i < n; ++i) std::cout << path[i] << " \n"[i == n - 1];
    return 0;
}
