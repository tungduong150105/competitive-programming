#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int h, w, k; std::cin >> h >> w >> k;
    std::vector<std::string> s(h);
    for (int i = 0; i < h; ++i) std::cin >> s[i];
    int ans = 1E9;
    for (int mask = 0; mask < (1 << h); ++mask) {
        bool ok = true;
        int sz = __builtin_popcount(mask) + 1, div = 0;
        std::vector<int> tot(sz, 0);
        for (int j = 0; j < w; ++j) {
            std::vector<int> totcur(sz, 0);
            for (int i = 0, cur = 0; i < h; ++i) {
                totcur[cur] += s[i][j] == '1';
                if (totcur[cur] > k) ok = false;
                if (mask >> i & 1) ++cur;
            }
            bool split = false;
            for (int i = 0; i < sz; ++i) {
                if (tot[i] + totcur[i] > k) split = true;
                tot[i] += totcur[i];
            }
            if (split) {
                tot = totcur;
                ++div;
            }
        }
        if (ok) ans = std::min(ans, div + sz - 1);
    }
    std::cout << ans << "\n";
    return 0;
}
// 12'
