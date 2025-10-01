#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, a, b; std::cin >> n >> a >> b;
    std::vector<int> h(n);
    for (int i = 0; i < n; ++i) std::cin >> h[i], ++h[i];
    constexpr int inf = int(1E9);
    std::vector dp(n, std::vector (17, std::vector<int> (17, inf)));
    std::vector prev(n, std::vector (17, std::vector<std::pair<int, int>> (17, {-1, -1})));
    dp[0][h[0]][0] = 0;
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 0; j <= 16; ++j) {
            for (int k = 0; k <= 16; ++k) {
                for (int l = 0; l <= 16; ++l) {
                    if (j - l * b <= 0 && dp[i][std::max(0, h[i] - a * l - b * k)][l] > dp[i - 1][j][k] + l) {
                        dp[i][std::max(0, h[i] - a * l - b * k)][l] = dp[i - 1][j][k] + l;
                        prev[i][std::max(0, h[i] - a * l - b * k)][l] = {j, k};
                    }
                }
            }
        }
    }
    int ans = inf;
    std::pair<int, int> cur;
    for (int i = 0; i <= 16; ++i) {
        if (h[n - 1] - i * b <= 0) {
            if (ans > dp[n - 2][0][i]) {
                ans = dp[n - 2][0][i];
                cur = {0, i};
            }
        }
    }
    std::vector<int> path;
    int idx = n - 2;
    while (idx) {
        auto [j, k] = prev[idx][cur.first][cur.second];
        int s = dp[idx][cur.first][cur.second] - dp[idx - 1][j][k];
        for (int i = 0; i < s; ++i) path.push_back(idx);
        --idx;
        cur = {j, k};
    }
    std::reverse(path.begin(), path.end());
    std::cout << ans << "\n";
    for (int i = 0; i < ans; ++i) std::cout << path[i] + 1 << " \n"[i == ans - 1];
    return 0;
}
