#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n, k; std::cin >> n >> k;
    std::string s; std::cin >> s;
    std::vector<int> a;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        int j = i;
        while (j < n && s[j] == s[i]) ++cnt, ++j;
        i = j - 1;
        a.push_back(cnt);
    }
    int ans = 0, res = 0, cur = s[0] == '1', ncur = cur;
    for (int i = 0, j = 0; i < int(a.size()); ++i) {
        res += a[i];
        k -= cur ^= 1;
        while (k < 0) {
            res -= a[j++];
            k += ncur ^= 1;
        }
        ans = std::max(ans,res);
    }
    std::cout << ans << "\n";
    return 0;
}

// 27'
