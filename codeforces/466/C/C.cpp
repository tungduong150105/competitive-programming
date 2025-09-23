#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n; std::cin >> n;
	std::vector<int64_t> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		if (i) a[i] += a[i - 1];
	}
	if (a[n - 1] % 3) std::cout << "0\n";
	else {
		int64_t x = a[n - 1] / 3;
		int64_t ans = 0;
		int cnt = 0;
		for (int i = 0; i < n - 1; ++i) {
			if (a[i] == 2 * x) ans += cnt;
			if (a[i] == x) ++cnt;
		}
		std::cout << ans << "\n";
	}
	return 0;
}