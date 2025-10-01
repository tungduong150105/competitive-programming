#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, t; std::cin >> n >> t;
    std::vector<std::tuple<int, int, int>> a(n);
    for (auto &[x, y, z] : a) std::cin >> x;
    for (auto &[x, y, z] : a) std::cin >> y;
    for (auto &[x, y, z] : a) std::cin >> z;
    // if i-th to j-th: x0 + x1 - (z0 + z1) * y1 - z0 * y0
    // if j-th to i-th: x0 + x1 - (z0 + z1) * y0 - z1 * y1
    // (z0 + z1) * y1 + z0 * y0 < (z0 + z1) * y0 + z1 * y1
    // z0 * y1 + z1 * y1 + z0 * y0 < z0 * y0 + z1 * y0 + z1 * y1
    // z0 * y1 < z1 * y0
    std::sort(a.begin(), a.end(), [&](const auto &lhs, const auto &rhs) {
        return int64_t(std::get<2>(lhs)) * std::get<1>(rhs) < int64_t(std::get<2>(rhs)) * std::get<1>(lhs);
    });
    std::vector<int64_t> dp(t + 1, 0);
    for (auto [x, y, z] : a) {
        for (int j = t; j >= z; --j) {
            dp[j] = std::max(dp[j], dp[j - z] + x - int64_t(j) * y);
        }
    }
    std::cout << *std::max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}
