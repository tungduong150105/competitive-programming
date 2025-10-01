#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::map<int, std::vector<int>> mp;
    for (int i = 0; i < n; ++i) mp[a[i]].push_back(i);
    std::sort(a.begin(), a.end());
    std::vector<int> g = {0};
    for (int i = 1; i < n; ++i) g.push_back(a[i] - a[i - 1]);
    std::vector<int> f(n + 2, -1E9), prv(n + 2, -1);
    std::pair<int, int> mx = {0, 0};
    for (int i = 3, j = 0; i <= n; ++i, ++j) {
        mx = std::max(mx, {f[j], j});
        f[i] = mx.first + g[i];
        prv[i] = mx.second;
    }
    int cur = mx.second, cnt = 0;
    std::vector<int> ans(n);
    for (int i = n; i > 0; --i) {
        if (i == cur) {
            ++cnt;
            cur = prv[cur];
        }
        ans[mp[a[i - 1]].back()] = cnt;
        mp[a[i - 1]].pop_back();
    }
    std::cout << a[n - 1] - a[0] - mx.first << " " << cnt + 1 << "\n";
    for (int i = 0; i < n; ++i) std::cout << ans[i] + 1 << " \n"[i == n - 1];
    return 0;
}
// a1, a2, a3
