#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    std::vector<int> f(n), cnt(1 << 9, 0);
    for (int i = 0; i < n; ++i) {
        int x; std::cin >> x;
        int fx = 0;
        while (x--) {
            int b; std::cin >> b; --b;
            fx |= (1 << b);
            f[i] = fx;
        }
        for (int mask = 0; mask < (1 << 9); ++mask) {
            if ((mask & fx) == fx) ++cnt[mask];
        }
    }
    std::vector<std::tuple<int, int, int>> ans(n + 1, {int(2E9) + 5, -1, -1});
    std::vector<std::pair<int, int>> g(1 << 9, {int(2E9) + 5, -1});
    for (int i = 0; i < m; ++i) {
        int c, x; std::cin >> c >> x;
        int fx = 0;
        while (x--) {
            int b; std::cin >> b; --b;
            fx |= (1 << b);
        }
        for (int mask = 0; mask < (1 << 9); ++mask) {
            if (g[mask].second == -1) continue;
            int new_mask = mask | fx;
            ans[cnt[new_mask]] = std::min(ans[cnt[new_mask]], {g[mask].first + c, g[mask].second, i});
        }
        g[fx] = std::min(g[fx], {c, i});
    }
    for (int i = n; i >= 0; --i) {
        auto [c, x, y] = ans[i];
        if (x != -1) {
            // std::cout << c << " ";
            std::cout << x + 1 << " " << y + 1 << "\n";
            break;
        }
    }
    return 0;
}
