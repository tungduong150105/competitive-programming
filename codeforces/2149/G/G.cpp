#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	std::mt19937 rng(static_cast<uint32_t>(std::chrono::steady_clock::now().time_since_epoch().count()));
	int t; std::cin >> t;
	while (t--) {
		int n, q; std::cin >> n >> q;
		std::vector<int> a(n);
		for (int i = 0; i < n; ++i) std::cin >> a[i];
		auto b = a;
		std::sort(b.begin(), b.end());
		b.erase(std::unique(b.begin(), b.end()), b.end());
		for (int i = 0; i < n; ++i) a[i] = int(std::lower_bound(b.begin(), b.end(), a[i]) - b.begin());
		std::vector idx(int(b.size()), std::vector<int>());
		for (int i = 0; i < n; ++i) idx[a[i]].push_back(i);
		while (q--) {
			int l, r; std::cin >> l >> r; --l, --r;
			std::set<int> ans;
			for (int i = 0; i < 50; ++i) {
				int x = std::uniform_int_distribution<int>(l, r)(rng);
				int lo = int(std::lower_bound(idx[a[x]].begin(), idx[a[x]].end(), l) - idx[a[x]].begin());
				int hi = int(std::lower_bound(idx[a[x]].begin(), idx[a[x]].end(), r + 1) - idx[a[x]].begin());
				if (hi - lo > (r - l + 1) / 3) {
					ans.insert(b[a[x]]);
				}
			}
			if (ans.size()) {
				for (int v : ans) std::cout << v << " \n"[v == *--ans.end()];
			} else {
				std::cout << "-1\n";
			}
		}
	}
	return 0;
}
