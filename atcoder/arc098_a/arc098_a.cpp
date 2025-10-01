#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    int sum = int(std::count(s.begin(), s.end(), 'E'));
    int ans = n, add = 0;
    for (int i = 0; i < n; ++i) {
        sum -= s[i] == 'E';
        ans = std::min(ans, sum + add);
        add += s[i] == 'W';
    }
    std::cout << ans << "\n";
    return 0;
}
// 4'53
