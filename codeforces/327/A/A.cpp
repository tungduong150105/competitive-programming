#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n; std::cin >> n;
	std::vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		a[i] += a[i - 1];
	}
	int tmp = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = std::max(ans, a[n] + i - 2 * a[i] + tmp);
		tmp = std::max(tmp, 2 * a[i] - i);
	}
	std::cout << ans << "\n";
	return 0;
}