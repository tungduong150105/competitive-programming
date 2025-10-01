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

struct Info {
    int64_t v = 0;
};

Info operator+(const Info &lhs, const Info &rhs) {
    return {std::max(lhs.v, rhs.v)};
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> compress;
    std::vector<std::tuple<int, int, int>> x;
    for (int i = 0; i < n; ++i) {
        int a, b, p; std::cin >> a >> b >> p;
        x.emplace_back(b, a, p);
        compress.push_back(a);
        compress.push_back(b);
    }
    std::sort(x.begin(), x.end());
    std::sort(compress.begin(), compress.end());
    for (auto &[b, a, p] : x) {
        b = int(std::lower_bound(compress.begin(), compress.end(), b) - compress.begin());
        a = int(std::lower_bound(compress.begin(), compress.end(), a) - compress.begin());
    }
    int m = int(compress.size());
    std::vector<int64_t> dp(m + 1, 0);
    Fenwick<Info> fen(m + 1);
    for (auto [b, a, p] : x) {
        dp[b] = fen.sum_prefix(a).v + p;
        fen.add(b, {dp[b]});
    }
    std::cout << *std::max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}
