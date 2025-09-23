#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	std::string s, t; std::cin >> s >> t;
	for (char &c : s) c = std::tolower(c);
	for (char &c : t) c = std::tolower(c);
	if (s == t) std::cout << "0\n";
	else if (s < t) std::cout << "-1\n";
	else std::cout << "1\n";
	return 0;
}