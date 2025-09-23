#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n, d; std::cin >> n >> d;
	std::vector<double> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	std::sort(a.begin(), a.end());
	double ans = 0;
	for (int i = 1; i < n; ++i) ans = std::max(ans, (a[i] - a[i - 1]) / 2.0);
	ans = std::max({ans, a[0], d - a.back()});
	std::cout << std::fixed << std::setprecision(2) << ans << "\n";
	return 0;
}