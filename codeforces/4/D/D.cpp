#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, h, w; std::cin >> n >> h >> w;
    std::vector<std::tuple<int, int, int>> a;
    for (int i = 0; i < n; ++i) {
        int x, y; std::cin >> x >> y;
        a.emplace_back(x, y, i);
    }
    std::sort(a.begin(), a.end());
    std::vector<int> dp(n, 0), prev(n, -1);
    for (auto [x, y, idx] : a) {
        if (x > h && y > w) dp[idx] = 1;
    }
    for (int i = 0; i < n; ++i) {
        auto [x, y, idx] = a[i];
        for (int j = i + 1; j < n; ++j) {
            auto [_x, _y, _idx] = a[j];
            if (dp[idx] && _x > x && _y > y && dp[_idx] < dp[idx] + 1) {
                dp[_idx] = dp[idx] + 1;
                prev[_idx] = idx;
            }
        }
    }
    int cur = int(std::distance(dp.begin(), std::max_element(dp.begin(), dp.end())));
    std::vector<int> path;
    while (cur != -1 && dp[cur]) {
        path.push_back(cur);
        cur = prev[cur];
    }
    std::reverse(path.begin(), path.end());
    std::cout << int(path.size()) << "\n";
    for (int v : path) std::cout << v + 1 << " \n"[v == path.back()];
    return 0;
}
