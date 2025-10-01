#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, k, q; std::cin >> n >> k >> q;
    std::vector<int> a(200005, 0);
    for (int i = 0; i < n; ++i) {
        int l, r; std::cin >> l >> r;
        ++a[l];
        --a[r + 1];
    }
    std::vector<int> b(200005, 0);
    for (int i = 1; i <= 200000; ++i) {
        a[i] += a[i - 1];
        b[i] += a[i] >= k;
        b[i] += b[i - 1];
    }
    while (q--) {
        int l, r; std::cin >> l >> r;
        std::cout << b[r] - b[l - 1] << "\n";
    }
    return 0;
}
