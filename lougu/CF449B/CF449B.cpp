#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n, m, k; std::cin >> n >> m >> k;
	std::vector adj(n, std::vector<std::tuple<int, int64_t, int>> ());
	for (int i = 0; i < m; ++i) {
	    int u, v, x; std::cin >> u >> v >> x; --u, --v;
		adj[u].push_back({v, x, 0});
		adj[v].push_back({u, x, 0});
	}
	std::vector<std::pair<int, int64_t>> tr;
	for (int i = 0; i < k; ++i) {
	    int s, y; std::cin >> s >> y; --s;
		tr.push_back({s, y});
		adj[0].push_back({s, y, 1});
	}
	constexpr int64_t inf = 1E18;
	std::vector<int64_t> d(n, inf);
	std::vector ways(n, std::vector<int64_t> (2, 0));
	std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>, std::greater<std::pair<int64_t, int>>> pq;
	d[0] = 0;
	ways[0][0] = 1;
	pq.push({0, 0});
	while (pq.size()) {
	    auto [du, u] = pq.top();
		pq.pop();
		if (d[u] != du) continue;
		for (auto [v, dv, spec] : adj[u]) {
		    if (d[v] > d[u] + dv) {
				d[v] = d[u] + dv;
				if (!spec) {
				    ways[v][0] = ways[u][0] || ways[u][1];
					ways[v][1] = 0;
				} else {
				    ways[v][0] = 0;
				    ways[v][1] = ways[u][0];
				}
				pq.push({d[v], v});
			} else if (d[v] == d[u] + dv) {
			    if (!spec) {
					ways[v][0] += ways[u][0] || ways[u][1];
				} else {
					ways[v][1] += ways[u][0];
				}
			}
		}
	}
	int ans = 0;
	for (auto [v, dv] : tr) {
	    if (d[v] < dv) ++ans;
		if (d[v] == dv && ways[v][0]) ++ans;
		if (d[v] == dv && !ways[v][0] && ways[v][1] > 1) ++ans, --ways[v][1];
	}
	// std::cout << ways[1][1] << " " << ways[1][0] << "\n";
	std::cout << ans << "\n";
	return 0;
}
// 37'38
