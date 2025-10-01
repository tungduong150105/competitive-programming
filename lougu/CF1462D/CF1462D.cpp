#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        int ans = 0;
        int s = 0;
        for (int i = 0; i < n; ++i) {
            int res = 0, cur = 0;
            s += a[i];
            for (int j = 0; j < n; ++j) {
                cur += a[j];
                if (cur == s) {
                    ++res;
                    cur = 0;
                } else if (cur > s) {
                    res = -1E9;
                    cur = 0;
                }
            }
            if (cur && cur != s) res = 0;
            ans = std::max(ans, res);
        }
        std::cout << n - ans << "\n";
    }
    return 0;
}
// 7'10
