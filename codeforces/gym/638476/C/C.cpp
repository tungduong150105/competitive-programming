#include "bits/stdc++.h"

template <class T = int64_t>
struct Fenwick {
    int n;
    std::vector<T> bit;
    Fenwick() : n(0) {}
    explicit Fenwick(int _n) { init(_n); }
    void init(int _n) {
        n = _n;
        bit.assign(n, T{});
    }
    void add(int idx, T delta) {
        assert(0 <= idx && idx < n);
        for (int i = idx + 1; i <= n; i += i & -i) {
            bit[i - 1] = bit[i - 1] + delta;
        }
    }
    T sum_prefix(int r) const {
        assert(0 <= r && r < n);
        T res{};
        for (int i = r; i > 0; i -= i & -i) {
            res = res + bit[i - 1];
        }
        return res;
    }
    T sum(int l, int r) const {
        assert(0 <= l && l <= r && r < n);
        return sum_prefix(r) - sum_prefix(l);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    Fenwick<int> fen(n + 3);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i] = std::min(a[i], n);
    }
    // [i + 1, a[i]] >= i
    // [1, a[i]] >= i - [1, i] >= i
    std::vector que(n + 1, std::vector<int>());
    for (int i = 1; i <= n; ++i) {
        if (i + 1 > a[i - 1]) continue;
        que[a[i - 1]].push_back(i);
    }
    int64_t ans = 0;
    for (int i = 1; i <= n; ++i) {
        fen.add(1, 1);
        fen.add(a[i - 1] + 1, -1);
        for (int v : que[i]) {
            // std::cout << i << " " << v << " " << fen.sum_prefix(v + 1) << "\n";
            ans += fen.sum_prefix(v + 1);
        }
        if (i + 1 > a[i - 1]) continue;
        ans -= fen.sum_prefix(i + 1);
       // std::cout << i << " " << fen.sum_prefix(i + 2) << "\n";
    }
    std::cout << ans << "\n";
    return 0;
}
