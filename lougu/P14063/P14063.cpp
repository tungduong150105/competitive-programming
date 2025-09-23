#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n, b; std::cin >> n >> b;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	int ans = 0, tot = 0;
	for (int i = 0, j = -1; i < n; ++i) {
		tot += a[i];
		while (tot > b) tot -= a[++j];
		ans = std::max(ans, i - j);
	}
	std::cout << ans << "\n";
	return 0;
}