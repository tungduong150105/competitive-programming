#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n; std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	std::sort(a.begin(), a.end());
	int q; std::cin >> q;
	while (q--) {
		int m; std::cin >> m;
		int l = std::lower_bound(a.begin(), a.end(), m + 1) - a.begin();
		std::cout << l << "\n";
	}
	return 0;
}

// 3'49