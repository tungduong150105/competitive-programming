#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int t; std::cin >> t;
	while (t--) {
		std::string s; std::cin >> s;
		int n = int(s.size());
		if (n > 10) std::cout << s[0] << n - 2 << s.back() << "\n";
		else std::cout << s << "\n";
	}
	return 0;
}