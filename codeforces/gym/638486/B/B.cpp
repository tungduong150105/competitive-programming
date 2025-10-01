#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, t; std::cin >> n >> t;
    std::vector<int> a(n + 1, 0);
    int ans = 0;
    for (int i = 1, j = 0; i <= n; ++i) {
        std::cin >> a[i];
        a[i] += a[i - 1];
        while (a[i] - a[j] > t) ++j;
        ans = std::max(ans, i - j);
    }
    std::cout << ans << "\n";
    return 0;
}
