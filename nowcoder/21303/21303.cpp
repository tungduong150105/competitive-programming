#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    std::string s, t; std::cin >> s >> t;
    int n = int(s.size()), m = int(t.size());
    std::vector dp(m + 1, std::vector (n + 1, std::vector<int> (n + 1, 0)));
    dp[0][0][0] = 1;
    for (int j = 0; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            for (int k = 0; k <= n; ++k) {
                if (j && !k && s[i - 1] == t[j - 1]) dp[j][i][k] |= dp[j - 1][i - 1][k];
                if (s[i - 1] == '(' && k) dp[j][i][k] |= dp[j][i - 1][k - 1];
                if (s[i - 1] == ')' && k < n) dp[j][i][k] |= dp[j][i - 1][k + 1];
            }
        }
    }
    std::cout << (dp[m][n][0] ? "Possible" : "Impossible") << "\n";
    return 0;
}
