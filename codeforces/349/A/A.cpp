#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n; std::cin >> n;
	std::vector<int> cnt(2, 0);
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		int x; std::cin >> x;
		if (x == 25) ++cnt[0];
		else if (x == 50) ++cnt[1], --cnt[0];
		else {
			if (cnt[1]) --cnt[1], --cnt[0];
			else cnt[0] -= 3;
		}
		if (cnt[0] < 0 || cnt[1] < 0) ok = false;
	}
	std::cout << (ok ? "YES" : "NO") << "\n";
	return 0;
}