#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::sort(a.begin(), a.end());
        int64_t ans = 0;
        auto count = [&](int x) -> int {
            int hi = int(std::lower_bound(a.begin(), a.end(), x + 1) - a.begin());
            int lo = int(std::lower_bound(a.begin(), a.end(), x) - a.begin());
            return hi - lo;
        };
        auto b = a;
        b.erase(std::unique(b.begin(), b.end()), b.end());
        for (int v : b) {
            int c0 = count(v - 2);
            int c1 = count(v - 1);
            int c2 = count(v);
            int c3 = count(v + 1);
            int c4 = count(v + 2);
            ans += 1LL * c1 * c2 * c3;
            ans += 1LL * c2 * (c2 - 1) / 2 * (c0 + c1 + c3 + c4);
            ans += 1LL * c2 * (c2 - 1) * (c2 - 2) / 6;
        }
        std::cout << ans << "\n";
    }
    return 0;
}
