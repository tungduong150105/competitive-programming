#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	std::string s; std::cin >> s;
	std::vector<int> a;
	for (char c : s) {
		if (std::isdigit(c)) a.push_back(c);
	}
	std::sort(a.begin(), a.end());
	int idx = 0;
	for (char &c : s) {
		if (std::isdigit(c)) c = a[idx++];
	}
	std::cout << s << "\n";
	return 0;
}