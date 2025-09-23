#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int m, s; std::cin >> m >> s;
	if (!s && m == 1) std::cout << "0 0\n";
	else if (!s || 9 * m < s) std::cout << "-1 -1\n";
	else {
		{
			int ss = s;
			std::vector<int> ans(m, 0);
			ans[0] = 1;
			--s;
			int cur = m - 1;
			while (cur >= 0) {
				int x = std::min(s, 9 - ans[cur]);
				ans[cur--] += x;
				s -= x;
			}
			for (int v : ans) std::cout << v;
			std::cout << " ";
			s = ss;
		}
		{
			std::vector<int> ans(m, 0);
			ans[0] = 1;
			--s;
			int cur = 0;
			while (cur < m) {
				int x = std::min(s, 9 - ans[cur]);
				ans[cur++] += x;
				s -= x;
			}
			for (int v : ans) std::cout << v;
			std::cout << "\n";
		}
	}
	return 0;
}