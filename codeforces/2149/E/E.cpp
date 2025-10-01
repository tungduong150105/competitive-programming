#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int t; std::cin >> t;
	while (t--) {
		int n, k, l, r; std::cin >> n >> k >> l >> r;
		std::vector<int> a(n);
		for (int i = 0; i < n; ++i) std::cin >> a[i];
		std::map<int, int> cnt, cnt2;
		int64_t ans = 0;
		int cur = 0, cur2 = 0, prv = 0;
		for (int i = 0, j = 0, j2 = 0; i < n; ++i) {
			++cnt[a[i]];
			++cnt2[a[i]];
			if (cnt[a[i]] == 1) ++cur;
			if (cnt2[a[i]] == 1) ++cur2;
			while (cur > k) {
				--cnt[a[j]];
				if (!cnt[a[j]]) --cur;
				++j;
				prv = j;
			}
			while (cur2 == k) {
				--cnt2[a[j2]];
				if (!cnt2[a[j2]]) --cur2;
				++j2;
			}
			if (cur == k && cur2 == k - 1) {
				int gl = i + 1 - r;
				int gr = i + 1 - l;
				int gx = std::max(gl, prv);
				int gy = std::min(j2 - 1, gr);
				ans += std::max(0, gy - gx + 1);
				// std::cout << i << " " << prv << " " << j2 - 1 << " " << gx << " " << gy << "\n";
			}
		}
		std::cout << ans << "\n";
	}
	return 0;
}
