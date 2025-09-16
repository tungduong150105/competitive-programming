#include "bits/stdc++.h"

template <typename T>
T power(T a, int64_t b) {
  T ans = 1;
  for (; b > 0; b /= 2, a *= a) {
    if (b % 2 == 1) {
      ans *= a;
    }
  }
  return ans;
}

template <int _MOD>
struct ModNum {
  static constexpr int MOD = _MOD;
  static_assert(MOD > 0, "MOD must be positive");
  int v;

  ModNum() : v(0) {
  }

  ModNum(int64_t _v) : v(int(_v % MOD)) {
    if (v < 0) {
      v += MOD;
    }
  }

  int val() const {
    return v;
  }

  ModNum inv() const {
    return power(*this, MOD - 2);
  }

  ModNum neg() const {
    ModNum res;
    res.v = v ? MOD - v : 0;
    return res;
  }

  ModNum operator-() const {
    return neg();
  }

  ModNum operator+() const {
    return ModNum(*this);
  }

  ModNum &operator+=(const ModNum &lhs) {
    v += lhs.v;
    if (v > MOD) {
      v -= MOD;
    }
    return *this;
  }

  ModNum &operator-=(const ModNum &lhs) {
    v -= lhs.v;
    if (v < 0) {
      v += MOD;
    }
    return *this;
  }

  ModNum &operator*=(const ModNum &lhs) {
    v = int(int64_t(v) * int64_t(lhs.v) % MOD);
    return *this;
  }

  ModNum &operator/=(const ModNum &lhs) {
    return *this *= lhs.inv();
  }

  friend ModNum operator+(const ModNum &lhs, const ModNum &rhs) {
    ModNum res = lhs;
    return res += rhs;
  }

  friend ModNum operator-(const ModNum &lhs, const ModNum &rhs) {
    ModNum res = lhs;
    return res -= rhs;
  }

  friend ModNum operator*(const ModNum &lhs, const ModNum &rhs) {
    ModNum res = lhs;
    return res *= rhs;
  }

  friend ModNum operator/(const ModNum &lhs, const ModNum &rhs) {
    ModNum res = lhs;
    return res /= rhs;
  }

  friend bool operator==(const ModNum &lhs, const ModNum &rhs) {
    return lhs.v == rhs.v;
  }

  friend bool operator!=(const ModNum &lhs, const ModNum &rhs) {
    return lhs.v != rhs.v;
  }

  friend std::ostream &operator<<(std::ostream &out, const ModNum &lhs) {
    return out << lhs.val();
  }

  friend std::istream &operator>>(std::istream &in, ModNum &lhs) {
    int64_t _v;
    in >> _v;
    lhs = ModNum(_v);
    return lhs;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  using Z = ModNum<1000000007>;

  int T;
  std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n, m;
    std::cin >> n >> m;

    int k;
    std::cin >> k;
    std::vector<int> c(k);
    for (int i = 0; i < k; ++i) {
      std::cin >> c[i];
    }

    std::vector dp(n, std::vector<int>(1 << n, 0));
    for (int i = 0; i < n; ++i) {
      for (int mask = 0; mask < (1 << n); ++mask) {
        dp[i][mask] = i % 2 == 0 ? 0 : 10;
      }
    }

    dp[n - 1][0] = 0;
    dp[n - 1][1] = 1;
    for (int i = n - 2; i >= 0; --i) {
      for (int mask = 0; mask < (1 << n); ++mask) {
        int num = n - i;
        if ((mask >> num) > 0) {
          continue;
        }
        for (int j = 0; j < k; ++j) {
          int shift = c[j];
          if (shift > num) {
            continue;
          }
          int new_mask = 0;
          for (int l = 0; l < shift - 1; ++l) {
            new_mask |= (mask >> l & 1) << l;
          }
          for (int l = shift; l < n; ++l) {
            new_mask |= (mask >> l & 1) << (l - 1);
          }
          if (dp[i + 1][new_mask] != 10) {
            if (i % 2 == 0) {
              dp[i][mask] = std::max(dp[i][mask], dp[i + 1][new_mask]);
            } else {
              dp[i][mask] = std::min(dp[i][mask], dp[i + 1][new_mask]);
            }
          }
        }
      }
    }

    std::vector<int> cnt(n + 1, 0);
    for (int mask = 0; mask < (1 << n); ++mask) {
      cnt[__builtin_popcount(mask)] += dp[0][mask];
    }

    Z ans = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        ans += power(Z(i - 1), n - j) * power(Z(m - i + 1), j) * Z(cnt[j]);
        // std::cout << power(Z(i - 1), n - j) << " " << ans << "gg\n";
      }
    }

    std::cout << ans << "\n";
  }

  return 0;
}
