#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, s; std::cin >> n >> s;
    std::vector prev(n + 1, std::vector<int> (s + 1, -1));
    prev[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int l, r; std::cin >> l >> r;
        for (int j = s; j >= l; --j) {
            for (int t = l; t <= r; ++t) {
                if (j - t >= 0 && prev[i][j - t] != -1) prev[i + 1][j] = j - t;
            }
        }
    }
    if (prev[n][s] != -1) {
        std::cout << "YES\n";
        std::vector<int> path;
        int cur = n;
        while (cur) {
            // std::cout << s << " ";
            path.push_back(s - prev[cur][s]);
            s = prev[cur][s];
            --cur;
        }
        std::reverse(path.begin(), path.end());
        for (int i = 0; i < n; ++i) std::cout << path[i] << " \n"[i == n - 1];
    } else {
        std::cout << "NO\n";
    }
    return 0;
}
