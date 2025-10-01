#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n; std::cin >> n;
	std::vector<int> dp(3, 0);
	for (int i = 1; i <= n; ++i) {
		int x; std::cin >> x;
		std::vector<int> ndp(3, 0);
		ndp[2] = std::max({dp[0], dp[1], dp[2]});
		if (x == 1 || x == 3) ndp[1] = std::max(dp[0], dp[2]) + 1;
		if (x == 2 || x == 3) ndp[0] = std::max(dp[1], dp[2]) + 1;
		std::swap(dp, ndp);
	}
	std::cout << n - std::max({dp[0], dp[1], dp[2]}) << "\n";

	return 0;
}
// 14'21