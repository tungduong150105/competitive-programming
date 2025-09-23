#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n; std::cin >> n;
	int ans = 0, res = 0, last = 0;
	for (int i = 0; i < n; ++i) {
		int x; std::cin >> x;
		if (x > last) ++res;
		else res = 1;
		last = x;
		ans = std::max(ans, res);
	}
	std::cout << ans << "\n";
	return 0;
}