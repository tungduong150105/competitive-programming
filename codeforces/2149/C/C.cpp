#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int t; std::cin >> t;
	while (t--) {
		int n, k; std::cin >> n >> k;
		std::vector<int> a(n);
		std::set<int> g;
		int eq = 0;
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
			if (a[i] < k) g.insert(a[i]);
			eq += a[i] == k;
		}
		std::cout << eq + std::max(0, (k - int(g.size())) - eq) << "\n";
	}
	return 0;
}