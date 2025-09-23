#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int t; std::cin >> t;
	while (t--) {
		int l, r; std::cin >> l >> r;
		std::vector<int> ans(r - l + 1);
		std::iota(ans.begin(), ans.end(), l);
		int L = 0, R = r - l + 1;
		for (int i = 29; i >= 0; --i) {
			int x = L;
			while (x < R && (~ans[x] >> i & 1)) ++x;
			int lf_sz = x - L, rt_sz = R - x;
			if (lf_sz < rt_sz) {
				std::reverse(ans.begin() + L, ans.begin() + L + 2 * lf_sz);
				L += 2 * lf_sz;
			} else {
				std::reverse(ans.begin() + R - 2 * rt_sz, ans.begin() + R);
				R -= 2 * rt_sz;
			}
		}
		int64_t tot = 0;
		for (int i = 0; i < int(ans.size()); ++i) tot += ans[i] | (l + i);
		std::cout << tot << "\n";
		for (int v : ans) std::cout << v << " \n"[v == ans.back()];
	}
	return 0;
}

// L, .... x, .... R
// 000
// 001
// 010
// 011
// 100
// 101
// 110
// 111