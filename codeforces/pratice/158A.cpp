#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n, k; std::cin >> n >> k;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	int ans = 0;
	for (int i = 0; i < int(a.size()); ++i) ans += a[i] >= a[k - 1] && a[i];
	std::cout << ans << "\n";
	return 0;
}