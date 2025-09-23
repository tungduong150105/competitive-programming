#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int t; std::cin >> t;
	while (t--) {
		int n; std::cin >> n;
		std::vector<int> cnt(n);
		for (int i = 0; i < n; ++i) {
			int x; std::cin >> x; --x;
			++cnt[x];
		}
		std::sort(cnt.begin(), cnt.end(), std::greater<>());
		int ans = 0, s = 1;
		for (int v : cnt) {
			ans = std::max(ans, v * s++);
		}
		std::cout << ans << "\n";
	}
	return 0;
}