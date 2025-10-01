#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::vector<int> x(n), y(n);
        x[0] = 0, y[0] = a[0];
        for (int i = 1; i < n; ++i) {
            x[i] = std::max(x[i - 1], a[i] - y[i - 1]);
            y[i] = a[i] - x[i];
        }
        // for (int v : y) std::cout << v << " ";
        // std::cout << "\n";
        bool ok = *std::min_element(y.begin(), y.end()) >= 0;
        std::cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}

// x[i-1] <= x[i]
// a[i] - x[i] >= y[i-1]
// x[i] >= (x[i-1], a[i]-y[i-1])
