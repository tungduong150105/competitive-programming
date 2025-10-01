#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int m, s; std::cin >> m >> s;
	if (!s && m == 1) {
		std::cout << "0 0\n";
	} else if (!s || s > 9 * m) {
		std::cout << "-1 -1\n";
	} else {
		{
			int rem = s - 1;
			std::vector<int> ans;
			ans.push_back(1);
			for (int i = 1; i < m; ++i) ans.push_back(0);
			for (int i = m - 1; i >= 0; --i) {
				int add = std::min(rem, 9 - ans[i]);
				ans[i] += add;
				rem -= add;
			}
			for (int v : ans) std::cout << v;
			std::cout << " ";
		}
		{
			int rem = s - 1;
			std::vector<int> ans;
			ans.push_back(1);
			for (int i = 1; i < m; ++i) ans.push_back(0);
			for (int i = 0; i < m; ++i) {
				int add = std::min(rem, 9 - ans[i]);
				ans[i] += add;
				rem -= add;
			}
			for (int v : ans) std::cout << v;
			std::cout << "\n";
		}
	}
	return 0;
}

// 6'31