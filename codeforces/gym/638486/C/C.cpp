#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) {
        std::string s; std::cin >> s;
        std::deque<char> dq;
        std::string ans;
        for (char v : s) {
            if (dq.empty()) {
                dq.push_back(v);
            } else {
                if ((dq.back() & 1) == (v & 1)) {
                    dq.push_back(v);
                } else {
                    while (dq.size() && dq.front() < v) ans += dq.front(), dq.pop_front();
                    if (dq.size()) {
                        ans += v;
                    } else {
                        dq.push_back(v);
                    }
                }
            }
        }
        while (dq.size()) ans += dq.front(), dq.pop_front();
        std::cout << ans << "\n";
    }
    return 0;
}
