#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n, m; std::cin >> n >> m;
	std::vector<std::vector<int>> a(n, std::vector<int> (m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> a[i][j];
		}
	}
	std::vector dp(4, std::vector (n + 2, std::vector<int64_t> (m + 2, 0)));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[0][i][j] = std::max(dp[0][i - 1][j], dp[0][i][j - 1]) + a[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = m; j >= 1; --j) {
			dp[1][i][j] = std::max(dp[1][i - 1][j], dp[1][i][j + 1]) + a[i - 1][j - 1];
		}
	}
	for (int i = n; i >= 1; --i) {
		for (int j = m; j >= 1; --j) {
			dp[2][i][j] = std::max(dp[2][i + 1][j], dp[2][i][j + 1]) + a[i - 1][j - 1];
		}
	}
	for (int i = n; i >= 1; --i) {
		for (int j = 1; j <= m; ++j) {
			dp[3][i][j] = std::max(dp[3][i + 1][j], dp[3][i][j - 1]) + a[i - 1][j - 1];
		}
	}
	int64_t ans = 0;
	for (int i = 2; i < n; ++i) {
		for (int j = 2; j < m; ++j) {
			ans = std::max(ans, dp[0][i][j - 1] + dp[1][i - 1][j] + dp[2][i][j + 1] + dp[3][i + 1][j]);
			ans = std::max(ans, dp[0][i - 1][j] + dp[1][i][j + 1] + dp[2][i + 1][j] + dp[3][i][j - 1]);
		}
	}
	std::cout << ans << "\n";
	return 0;
}