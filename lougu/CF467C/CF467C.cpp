#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n, m, k; std::cin >> n >> m >> k;
	std::vector<int64_t> p(n);
	std::vector dp(n, std::vector<int64_t> (k + 1, 0));
	for (int i = 0; i < n; ++i) {
		std::cin >> p[i];
		if (i) p[i] += p[i - 1];
		for (int j = 0; j <= k; ++j) {
			if (i) dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
		}
		for (int j = 1; j <= k; ++j) {
			if (i + 1 >= m) {
				int64_t prs = p[i] - (i >= m ? p[i - m] : 0);
				dp[i][j] = std::max(dp[i][j], (i >= m ? dp[i - m][j - 1] : 0LL) + prs);
			}
		}
	}
	std::cout << dp[n - 1][k] << "\n";
	return 0;
}

// 17'01