#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n, m; std::cin >> n >> m;
	if (std::min(n, m) & 1) std::cout << "Akshat\n";
	else std::cout << "Malvika\n";
	return 0;
}