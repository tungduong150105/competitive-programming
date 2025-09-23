#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int t; std::cin >> t;
	while (t--) {
		int l, r; std::cin >> l >> r;
		std::vector<int> ans;
		std::deque<int> g(r + 1);
		std::iota(g.begin(), g.end(), 0);
		auto f = [&]() -> void {
			int sz = (r + 1) - int(ans.size());
			int s = 1;
			while (s * 2 <= sz) s *= 2;
			std::reverse(g.begin(), g.begin() + s);
			for (int i = s; i < int(g.size()); ++i) {
				std::swap(g[i], g[(s - 1) - (i - s)]);
			}
			for (int i = 0; i < s; ++i) ans.push_back(g[0]), g.pop_front();
		};
		while (int(ans.size()) < r + 1) f();
		int64_t tot = 0;
		for (int i = 0; i <= r; ++i) tot += (ans[i] | i);
		std::cout << tot << "\n";
		for (int v : ans) {
			std::cout << v << " \n"[v == ans.back()];
		}
	}
	return 0;
}