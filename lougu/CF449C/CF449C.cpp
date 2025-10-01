#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n; std::cin >> n;
	std::vector<int> vis(n + 1, false);
	std::vector<std::pair<int, int>> ans;
	std::vector<bool> pr(n + 1, false);
	for (int i = 2; i * i <= n; ++i) {
		if (!pr[i]) {
			for (int j = i * i; j <= n; j += i) pr[j] = true;
		}
	}
	std::vector<int> lpr;
	for (int i = 3; i <= n; i += 2) {
		if (!pr[i]) lpr.push_back(i);
	}
	lpr.push_back(2);
	for (int x : lpr) {
		std::vector<int> g;
		for (int j = x; j <= n; j += x) {
			if (!vis[j]) {
				vis[j] = true;
				g.push_back(j);
			}
		}
		int sz = int(g.size());
		int prv = -1;
		for (int v : g) {
			if (v == 2 * x && sz & 1) {
				vis[v] = false;
				continue;
			}
			if (prv == -1) {
				prv = v;
			} else {
				ans.push_back({prv, v});
				prv = -1;
			}
		}
	}
	std::cout << ans.size() << "\n";
	for (auto [a, b] : ans) {
		std::cout << a << " " << b << "\n";
	}
	return 0;
}

// 38'19