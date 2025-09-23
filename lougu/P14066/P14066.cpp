#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n; std::cin >> n;
	std::vector<int> a(n);
	std::vector<std::vector<int>> g(n + 1);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		g[a[i]].push_back(i);
	}
	std::sort(a.begin(), a.end(), std::greater<>());
	auto b = a;
	std::reverse(b.begin(), b.end());
	std::vector<int> ans(n, 0);
	bool hans = false;
	for (int i = 0, j = n - 1; i < n - 2; ++i) {
		while (j > 0 && a[j - 1] <= i + 1) --j;
		if (i + 1 + a[0] < n && i + 1 + a[0] + a[i + 1] <= n && a[i + 1] <= n - j) {
			int ts = n - (i + 1 + a[0]);
			// std::cout << i + 1 << " " << a[0] + ts - a[i + 1] << " " << a[i + 1] << "\n";
			for (int k = 0; k < i + 1; ++k) {
				ans[g[a[k]].back()] = 1;
				g[a[k]].pop_back();
			}
			for (int k = i + 1; k < i + 1 + a[0] + n - (i + 1 + a[0]) - a[i + 1]; ++k) {
				ans[g[a[k]].back()] = 2;
				g[a[k]].pop_back();
			}
			hans = true;
			break;
		}
		if (i + 1 + a[0] < n && i + 1 + a[0] + b[a[0] - 1] <= n && a[i + 1] <= i + 1) {
			for (int k = 0; k < i + 1; ++k) {
				ans[g[a[k]].back()] = 1;
				g[a[k]].pop_back();
			}
			for (int k = 0; k < a[0]; ++k) {
				ans[g[b[k]].back()] = 2;
				g[b[k]].pop_back();
			}
			hans = true;
			break;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!ans[i]) ans[i] = 3;
	}
	if (hans) {
		std::cout << "YES\n";
		for (int v : ans) std::cout << v;
		std::cout << "\n";
	} else {
		std::cout << "NO\n";
	}
	return 0;
}