#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int r, c; std::cin >> r >> c;
	std::vector<std::string> a(r);
	for (int i = 0; i < r; ++i) std::cin >> a[i];
	int lo = -1, hi = r * c;
	while (hi - lo > 1) {
		int m = (lo + hi) / 2;
		auto f = [&]() -> bool {
			std::vector<std::string> b = a;
			{
				std::vector<int> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
				std::queue<std::array<int, 3>> bfs;
				for (int i = 0; i < r; ++i) {
					for (int j = 0; j < c; ++j) {
						if (a[i][j] == 'R') bfs.push({0, i, j});
					}
				}
				while (bfs.size()) {
					auto v = bfs.front();
					bfs.pop();
					if (v[0] == m) continue;
					for (int i = 0; i < 4; ++i) {
						int nx = v[1] + dx[i], ny = v[2] + dy[i];
						if (nx >= 0 && nx < r && ny >= 0 && ny < c && b[nx][ny] != 'R') {
							bfs.push({v[0] + 1, nx, ny});
							b[nx][ny] = 'R';
						}
					}
				}
			}
			{
				std::vector<int> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
				std::queue<std::array<int, 3>> bfs;
				std::vector vis(r, std::vector (c, std::vector<bool> (4, false)));
				for (int i = 0; i < r; ++i) {
					for (int j = 0; j < c; ++j) {
						if (b[i][j] == 'A') {
							bfs.push({0, i, j});
							bfs.push({1, i, j});
							bfs.push({2, i, j});
							bfs.push({3, i, j});
							vis[i][j][0] = true;
							vis[i][j][1] = true;
							vis[i][j][2] = true;
							vis[i][j][3] = true;
						}
					}
				}
				while (bfs.size()) {
					auto v = bfs.front();
					bfs.pop();
					if (b[v[1]][v[2]] == 'K') return false;
					if (b[v[1]][v[2]] != 'o') {
						int nx = v[1] + dx[v[0]], ny = v[2] + dy[v[0]];
						if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
							if (b[nx][ny] == 'R') continue;
							if (vis[nx][ny][v[0]]) continue;
							bfs.push({v[0], nx, ny});
							vis[nx][ny][v[0]] = true;
						}
					} else {
						for (int i = 0; i < 4; ++i) {
							int nx = v[1] + dx[i], ny = v[2] + dy[i];
							if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
								if (b[nx][ny] == 'R') continue;
								if (vis[nx][ny][i]) continue;
								bfs.push({i, nx, ny});
								vis[nx][ny][i] = true;
							}
						}
					}
				}
			}
			return true;
		};
		if (f()) {
			hi = m;
		} else {
			lo = m;
		}
	}
	std::cout << hi << "\n";
	return 0;
}