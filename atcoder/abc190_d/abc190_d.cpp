#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int64_t n; std::cin >> n;
    // x*l + l*(l-1)/2 = n => 2*x*l + l^2 - l = 2*n => l^2 + l(2*x-1) = 2n
    int64_t ans = 0;
    for (int64_t l = 1; l * l <= 2LL * n; ++l) {
        int64_t x = ((2LL * n - l * l) / l + 1) / 2;
        if (l * l + l * (2LL * x - 1) == 2 * n && x) {
            // std::cout << l << " " << x << "\n";
            ans += 2;
        }
    }
    std::cout << ans << "\n";
    return 0;
}
// 18'22
