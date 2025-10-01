#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, k; std::cin >> n >> k;
    std::vector<int> h(n);
    for (int i = 0; i < n; ++i) std::cin >> h[i];
    int lo = 1, hi = n + 1;
    while (hi - lo > 1) {
        int m = (lo + hi) / 2;
        bool valid = false;
        std::multiset<int> ms;
        for (int i = 0; i < m; ++i) ms.insert(h[i]);
        if (*--ms.end() - *ms.begin() <= k) valid = true;
        for (int i = m, j = 0; i < n; ++i, ++j) {
            ms.erase(ms.find(h[j]));
            ms.insert(h[i]);
            if (*--ms.end() - *ms.begin() <= k) valid = true;
        }
        if (valid) {
            lo = m;
        } else {
            hi = m;
        }
    }
    std::vector<std::pair<int, int>> fans;
    std::multiset<int> ms;
    for (int i = 0; i < lo; ++i) ms.insert(h[i]);
    if (*--ms.end() - *ms.begin() <= k) fans.emplace_back(0, lo - 1);
    for (int i = lo, j = 0; i < n; ++i, ++j) {
        ms.erase(ms.find(h[j]));
        ms.insert(h[i]);
        if (*--ms.end() - *ms.begin() <= k) fans.emplace_back(j + 1, i);
    }
    std::cout << lo << " " << int(fans.size()) << "\n";
    for (auto [l, r] : fans) std::cout << l + 1 << " " << r + 1 << "\n";
    return 0;
}
