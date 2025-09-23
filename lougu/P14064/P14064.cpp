#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n, m; std::cin >> n >> m;
	std::vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	for (int i = 0; i < m; ++i) std::cin >> b[i];
	std::sort(a.begin(), a.end(), std::greater<>());
	std::sort(b.begin(), b.end(), std::greater<>());
	std::vector<int64_t> pref(n), suff(n);
	for (int i = 0; i < n; ++i) {
		pref[i] = std::abs(a[i] - b[i]);
		if (i) pref[i] += pref[i - 1];
	}
	for (int i = n - 1; i >= 0; --i) {
		suff[i] = std::abs(a[i] - b[i + (m - n)]);
		if (i < n - 1) suff[i] += suff[i + 1];
	}
	int64_t ans = 1E18;
	for (int i = 0; i <= n; ++i) {
		int64_t lf = i ? pref[i - 1] : 0;
		int64_t rt = i < n ? suff[i] : 0;
		ans = std::min(ans, lf + rt);
	}
	std::cout << ans << "\n";
	return 0;
}