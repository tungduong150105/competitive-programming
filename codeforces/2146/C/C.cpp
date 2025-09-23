#include "bits/stdc++.h"

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int t; std::cin >> t;
	while (t--) {
		int n; std::cin >> n;
		std::string s; std::cin >> s;
		std::vector<int> ans;
		std::vector<int> rem;
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1') {
				if (int(rem.size()) == 1) ok = false;
				while (rem.size()) ans.push_back(rem.back()), rem.pop_back();
				ans.push_back(i + 1);
			} else {
				rem.push_back(i + 1);
			}
		}
		if (int(rem.size()) == 1) ok = false;
		while (rem.size()) ans.push_back(rem.back()), rem.pop_back();
		if (ok) {
			std::cout << "YES\n";
			for (int v : ans) {
				std::cout << v << " \n"[v == ans.back()];
			}
		} else {
			std::cout << "NO\n";
		}
	}
	return 0;
}