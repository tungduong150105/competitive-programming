#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (i) a[i] += a[i - 1];
    }
    int q; std::cin >> q;
    while (q--) {
        int x; std::cin >> x;
        std::cout << int(std::lower_bound(a.begin(), a.end(), x) - a.begin()) + 1 << "\n";
    }
    return 0;
}
