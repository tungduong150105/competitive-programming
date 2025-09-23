#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n, m; std::cin >> n >> m;
	std::vector<std::vector<int>> adj(n);
	for (int i = 0; i < n - 1; ++i) {
		int p; std::cin >> p; --p;
		adj[p].push_back(i + 1);
	}
	int timer = 0;
	std::string s; std::cin >> s;
	std::vector<std::vector<std::pair<int, int>>> g(n + 1);
	for (int i = 0; i <= n; ++i) g[i].push_back(std::make_pair(-1, 0));
	std::vector<int> dep(n, 0), in(n), ot(n), sta(n + 1, 0);
	dep[0] = 1;
	auto dfs = [&](auto && self, int u, int p) -> void {
		in[u] = timer++;
		sta[dep[u]] ^= (1 << (s[u] - 'a'));
		g[dep[u]].push_back(std::make_pair(in[u], sta[dep[u]]));
		for (int v : adj[u]) {
			if (v == p) continue;
			dep[v] = dep[u] + 1;
			self(self, v, u);
		}
		ot[u] = timer;
	};
	dfs(dfs, 0, -1);
	while (m--) {
		int v, h; std::cin >> v >> h; --v;
		int lo = std::lower_bound(g[h].begin(), g[h].end(), std::make_pair(ot[v], -1)) - g[h].begin();
		assert(lo);
		--lo;
		int x = g[h][lo].second;
		lo = std::lower_bound(g[h].begin(), g[h].end(), std::make_pair(in[v], -1)) - g[h].begin();
		assert(lo);
		--lo;
		x ^= g[h][lo].second;
		std::cout << (__builtin_popcount(x) <= 1 ? "Yes" : "No") << "\n";
	}
	return 0;
}