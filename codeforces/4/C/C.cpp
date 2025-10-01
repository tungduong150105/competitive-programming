#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::map<std::string, int> mp;
    for (int i = 0; i < n; ++i) {
        std::string s; std::cin >> s;
        ++mp[s];
        if (mp[s] == 1) {
            std::cout << "OK\n";
        } else {
            std::cout << s << mp[s] - 1 << "\n";
        }
    }
    return 0;
}
