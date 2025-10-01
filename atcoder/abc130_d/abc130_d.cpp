#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    int64_t k; std::cin >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    int64_t ans = 0, sum = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        sum += a[i];
        while (sum >= k) sum -= a[j++];
        ans -= i - j + 1;
    }
    ans += 1LL * n * (n + 1) / 2;
    std::cout << ans << "\n";
    return 0;
}
// 4'35
