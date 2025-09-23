#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int t; std::cin >> t;
	while (t--) {
		int n, m; std::cin >> n >> m;
		std::vector<int> cnt(m, 0);
		std::vector<std::vector<int>> a(n);
		for (int i = 0; i < n; ++i) {
			int sz; std::cin >> sz;
			while (sz--) {
				int x; std::cin >> x; --x;
				a[i].push_back(x);
				++cnt[x];
			}
		}
		int s = 0;
		for (int i = 0; i < m; ++i) {
			if (!cnt[i]) s = -n;
		}
		for (int i = 0; i < n; ++i) {
			bool ok = true;
			for (int v : a[i]) {
				if (cnt[v] == 1) ok = false;
			}
			s += ok;
		}
		std::cout << (s >= 2 ? "YES" : "NO") << "\n";
	}
	return 0;
}