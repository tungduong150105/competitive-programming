#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int t; std::cin >> t;
	while (t--) {
		int n; std::cin >> n;
		std::vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
		}
		std::sort(a.begin(), a.end());
		int ans = 0;
		for (int i = 1; i < n; i += 2) ans = std::max(ans, a[i] - a[i - 1]);
		std::cout << ans << "\n";
	}
	return 0;
}