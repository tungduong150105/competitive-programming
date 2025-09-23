#include <algorithm>
#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n, m, q; std::cin >> n >> m >> q;
	std::vector<int> p(n), mx(n, 0);
	std::iota(p.begin(), p.end(), 0);
	auto find = [&](auto && self, int x) -> int {
		return p[x] == x ? x : (p[x] = self(self, p[x]));
	};
	auto merge = [&](int u, int v) -> void {
		int _u = find(find, u), _v = find(find, v);
		if (_u == _v) return;
		int l = mx[_u] / 2 + (mx[_u] % 2);
		int r = mx[_v] / 2 + (mx[_v] % 2);
		if (_u > _v) std::swap(_u, _v);
		p[_v] = _u;
		mx[_u] = std::max({mx[_u], mx[_v], l + r + 1});
	};
	std::vector<std::vector<int>> adj(n);
	for (int i = 0; i < m; ++i) {
		int a, b; std::cin >> a >> b; --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		merge(a, b);
	}
	std::pair<int, int> _mx;
	std::vector<int> dep(n, 0);
	auto dfs = [&](auto && self, int u, int p) -> void {
		_mx = std::max(_mx, std::make_pair(dep[u], u));
		for (int v : adj[u]) {
			if (v == p) continue;
			dep[v] = dep[u] + 1;
			self(self, v, u);
		}
	};
	for (int i = 0; i < n; ++i) {
		if (find(find, i) == i) {
			_mx = std::make_pair(0, i);
			dfs(dfs, i, -1);
			dep[_mx.second] = 0;
			dfs(dfs, _mx.second, -1);
			mx[i] = _mx.first;
		}
	}
	while (q--) {
		int cmd; std::cin >> cmd;
		if (cmd == 1) {
			int u; std::cin >> u; --u;
			std::cout << mx[find(find, u)] << "\n";
		} else {
			int u, v; std::cin >> u >> v; --u, --v;
			merge(u, v);
		}
	}
	return 0;
}