#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        std::string s; std::cin >> s;
        std::vector f(2, std::vector<int>());
        std::vector<int> ans;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            int x = s[i] & 1;
            if (f[x ^ 1].size()) {
                int v = f[x ^ 1].back();
                ans.push_back(v);
                f[x ^ 1].pop_back();
                f[x].push_back(v);
            } else {
                f[x].push_back(cur++);
                ans.push_back(cur - 1);
            }
        }
        std::cout << cur << "\n";
        for (int i = 0; i < n; ++i) std::cout << ans[i] + 1 << " \n"[i == n - 1];
    }
    return 0;
}
