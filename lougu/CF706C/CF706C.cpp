#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n; std::cin >> n;
	std::vector<int> c(n);
	for (int i = 0; i < n; ++i) std::cin >> c[i];
	std::vector<std::string> s(n);
	for (int i = 0; i < n; ++i) std::cin >> s[i];
	constexpr int64_t inf = 1E18;
	std::vector<int64_t> dp(2, 0);
	dp[1] = c[0];
	for (int i = 1; i < n; ++i) {
		std::string ar = s[i - 1];
		std::reverse(ar.begin(), ar.end());
		std::string br = s[i];
		std::reverse(br.begin(), br.end());
		std::vector<int64_t> ndp(2, inf);
		if (s[i - 1] <= s[i]) ndp[0] = std::min(ndp[0], dp[0]);
		if (ar <= s[i]) ndp[0] = std::min(ndp[0], dp[1]);
		if (s[i - 1] <= br) ndp[1] = std::min(ndp[1], dp[0] + c[i]);
		if (ar <= br) ndp[1] = std::min(ndp[1], dp[1] + c[i]);
		std::swap(dp, ndp);
	}
	int64_t ans = std::min(dp[0], dp[1]);
	if (ans == inf) ans = -1;
	std::cout << ans << "\n";
	return 0;
}

// 7'04