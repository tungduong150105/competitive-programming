#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    int L = 0, R = n - 1;
    std::string ans = "";
    int cur = 0;
    while (L <= R && std::max(a[L], a[R]) > cur) {
        if (a[L] < a[R] && a[L] > cur) {
            ans += 'L';
            cur = a[L];
            ++L;
        } else if (a[R] > cur) {
            ans += 'R';
            cur = a[R];
            --R;
        } else if (a[L] > cur) {
            ans += 'L';
            cur = a[L];
            ++L;
        }
    }
    std::cout << int(ans.size()) << "\n" << ans << "\n";
    return 0;
}
