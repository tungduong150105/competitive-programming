#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n; std::cin >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		std::string s; std::cin >> s;
		if (s[0] == '+' || s.back() == '+') ++ans;
		else --ans;
	}
	std::cout << ans << "\n";
	return 0;
}