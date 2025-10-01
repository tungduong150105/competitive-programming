#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int t; std::cin >> t;
	while (t--) {
		int n; std::cin >> n;
		std::string s; std::cin >> s;
		std::vector<int64_t> gal(n + 1, 0), gbl(n + 1, 0), gar(n + 1, 0), gbr(n + 1, 0);
		auto lf = [&](char c) -> void {
			int64_t res = 0, sm = 0;
			for (int i = 0, j = 0; i < n; ++i) {
				if (s[i] == c) res += i - j++, ++sm;
				if (c == 'a') gal[sm] = res;
				if (c == 'b') gbl[sm] = res;
			}
		};
		auto rt = [&](char c) -> void {
			int64_t res = 0, sm = 0;
			for (int i = n - 1, j = n - 1; i >= 0; --i) {
				if (s[i] == c) res += j - i, --j, ++sm;
				if (c == 'a') gar[sm] = res;
				if (c == 'b') gbr[sm] = res;
			}
		};
		lf('a');
		lf('b');
		rt('a');
		rt('b');
		int b = 0;
		// std::cout << gal[1] << " " << gbl[1] << "\n";
		for (char c : s) b += c == 'b';
		int64_t ans = 1E18;
		for (int i = 0; i <= b; ++i) {
			ans = std::min(ans, gbl[i] + gbr[b - i]);
		}
		for (int i = 0; i <= n - b; ++i) {
			ans = std::min(ans, gal[i] + gar[n - b - i]);
		}
		std::cout << ans << "\n";
	}
	return 0;
}