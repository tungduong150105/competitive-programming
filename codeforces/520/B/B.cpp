#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n, m; std::cin >> n >> m;
	std::queue<std::pair<int, int>> bfs;
	bfs.push(std::make_pair(n, 0));
	std::vector<bool> vis(20000, false);
	vis[n] = true;
	while (bfs.size()) {
		auto [x, cnt] = bfs.front();
		bfs.pop();
		if (x == m) {
			std::cout << cnt << "\n";
			break;
		}
		if (x * 2 <= 20000 && !vis[x * 2]) {
			bfs.push(std::make_pair(x * 2, cnt + 1));
			vis[x * 2] = true;
		}
		if (x - 1 && !vis[x - 1]) {
			bfs.push(std::make_pair(x - 1, cnt + 1));	
			vis[x - 1] = true;
		}
	}
	return 0;
}