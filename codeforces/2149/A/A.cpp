#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int t; std::cin >> t;
	while (t--) {
		int n; std::cin >> n;
		std::vector<int> cnt(3, 0);
		for (int i = 0; i < n; ++i) {
			int x; std::cin >> x;
			++cnt[x + 1];
		}
		std::cout << (cnt[0] % 2) * 2 + cnt[1] << "\n";
	}
	return 0;
}