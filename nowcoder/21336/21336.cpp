#include "bits/stdc++.h"

template <int MOD> int mod_inv_int(int a) {
    int b = MOD, u = 1, w = 0;
    while (b != 0) {
        int t = a / b;
        a -= t * b; std::swap(a, b);
        u -= t * w; std::swap(u, w);
    }
    assert(a == 1);
    if (u < 0) u += MOD;
    return u;
}

template <typename T> T mod_inv(T x) {
    assert(x.v != 0);
    T r;
    r.v = mod_inv_int<T::mod()>(x.v);
    return r;
}

template <typename T> T pow(T base, int64_t exp) {
    T res(1);
    while (exp > 0) {
        if (exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

template <int MOD> struct ModNum {
    int v;
    constexpr ModNum() : v(0) {}
    template <class T> constexpr ModNum(T x) : v(norm(x)) {}
    static constexpr int mod() { return MOD; }
    template <class T> static constexpr int norm(T x) {
        int64_t m = static_cast<int64_t>(MOD);
        int64_t y = static_cast<int64_t>(x % m);
        if (y < 0) y += m;
        return static_cast<int>(y);
    }
    ModNum& operator+=(const ModNum& rhs) {
        v += rhs.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    ModNum& operator-=(const ModNum& rhs) {
        v -= rhs.v;
        if (v < 0) v += MOD;
        return *this;
    }
    ModNum& operator*=(const ModNum& rhs) {
        v = static_cast<int>((static_cast<__int128>(v) * rhs.v) % MOD);
        return *this;
    }
    ModNum& operator/=(const ModNum& rhs) {
        return *this *= mod_inv(rhs);
    }
    ModNum operator+() const { return *this; }
    ModNum operator-() const { return ModNum(v == 0 ? 0 : MOD - v); }
    friend ModNum operator+(ModNum lhs, const ModNum& rhs) { return lhs += rhs; }
    friend ModNum operator-(ModNum lhs, const ModNum& rhs) { return lhs -= rhs; }
    friend ModNum operator*(ModNum lhs, const ModNum& rhs) { return lhs *= rhs; }
    friend ModNum operator/(ModNum lhs, const ModNum& rhs) { return lhs /= rhs; }
    friend bool operator==(const ModNum& a, const ModNum& b) { return a.v == b.v; }
    friend bool operator!=(const ModNum& a, const ModNum& b) { return a.v != b.v; }
    friend std::istream& operator>>(std::istream& is, ModNum& x) {
        int64_t t; is >> t; x = ModNum(t); return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const ModNum& x) {
        return os << x.v;
    }
    ModNum inv() const { return mod_inv(*this); }
    ModNum pow(int64_t e) const { return mod_pow(*this, e); }
};

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    using num = ModNum<1000000009>;
    int n; std::cin >> n;
    std::vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    constexpr int lim = 60;
    std::vector dp(lim + 1, std::vector<num> (1 << n, 0));
    int init = 0;
    for (int i = 0; i < n; ++i) init |= (~a[i] >> lim & 1) << i;
    dp[0][init] = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] >> lim & 1) dp[0][init ^ (1 << i)] += 1;
    }
    // std::cout << init << "\n";
    // for (int i = 0; i < (1 << n); ++i) std::cout << dp[0][i] << " \n"[i == (1 << n) - 1];
    for (int i = 1; i <= lim; ++i) {
        for (int state = 0; state < (1 << n); ++state) {
            int new_state = state;
            for (int j = 0; j < n; ++j) {
                if ((new_state >> j & 1) && (a[j] >> (lim - i) & 1)) new_state ^= (1 << j);
            }
            dp[i][new_state] += dp[i - 1][state];
            for (int j = 0; j < n; ++j) {
                if (state >> j & 1) {
                    if (a[j] >> (lim - i) & 1) dp[i][new_state ^ (1 << j)] += dp[i - 1][state];
                } else {
                    dp[i][new_state] += dp[i - 1][state];
                }
            }
        }
    }
    // for (int i = 0; i <= lim; ++i) {
    //     for (int j = 0; j < (1 << n); ++j) std::cout << dp[i][j] << " \n"[j == (1 << n) - 1];
    // }
    num ans = 0;
    for (int i = 0; i < (1 << n); ++i) ans += dp[lim][i];
    std::cout << ans << "\n";
    return 0;
}

// 0011
// 0101
// dp[0][1] = 1, dp[0][3] = 1
