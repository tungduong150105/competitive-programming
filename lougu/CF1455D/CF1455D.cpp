#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) {
        int n, x; std::cin >> n >> x;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (std::is_sorted(a.begin(), a.end())) break;
            if (a[i] > x) std::swap(a[i], x), ++ans;
        }
        if (!std::is_sorted(a.begin(), a.end())) ans = -1;
        std::cout << ans << "\n";
    }
    return 0;
}
// 10'

// 2 3 5 4, x = 1
// 1 2 3 4, x = 5, => ans = 3
// 1 2 3 5, x = 4, => ans = -1
// 1 2 4 5, x = 3, => ans = -1
// 1 3 4 5, x = 2, => ans = -1
// 2 3 4 5, x = 1, => ans = -1
