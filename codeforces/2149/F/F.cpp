#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int t; std::cin >> t;
	while (t--) {
		int h, d; std::cin >> h >> d;
		int lo = 0, hi = d + 1;
		while (lo < hi) {
			int m = lo + (hi - lo) / 2;
			int s = d / (m + 1);
			int r = d % (m + 1);
			int64_t need = 1LL * (s + 1) * (s + 2) * r / 2 + 1LL * s * (s + 1) * (m + 1 - r) / 2;
			if (need < h + m) {
				hi = m;
			} else {
				lo = m + 1;
			}
		}
		std::cout << d + lo << "\n";
	}
	return 0;
}
