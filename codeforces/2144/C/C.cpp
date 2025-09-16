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

  ModNum& operator+=(const ModNum& lhs) {
    v += lhs.v;
    if (v > MOD) {
      v -= MOD;
    }
    return *this;
  }

  ModNum& operator-=(const ModNum& lhs) {
    v -= lhs.v;
    if (v < 0) {
      v += MOD;
    }
    return *this;
  }

  ModNum& operator*=(const ModNum& lhs) {
    v = int(int64_t(v) * int64_t(lhs.v) % MOD);
    return *this;
  }

  ModNum& operator/=(const ModNum& lhs) {
    return *this *= lhs.inv();
  }

  friend ModNum operator+(const ModNum& lhs, const ModNum& rhs) {
    ModNum res = lhs;
    return res += rhs;
  }

  friend ModNum operator-(const ModNum& lhs, const ModNum& rhs) {
    ModNum res = lhs;
    return res -= rhs;
  }

  friend ModNum operator*(const ModNum& lhs, const ModNum& rhs) {
    ModNum res = lhs;
    return res *= rhs;
  }

  friend ModNum operator/(const ModNum& lhs, const ModNum& rhs) {
    ModNum res = lhs;
    return res /= rhs;
  }

  friend bool operator==(const ModNum& lhs, const ModNum& rhs) {
    return lhs.v == rhs.v;
  }

  friend bool operator!=(const ModNum& lhs, const ModNum& rhs) {
    return lhs.v != rhs.v;
  }

  friend std::ostream& operator<<(std::ostream& out, const ModNum& lhs) {
    return out << lhs.val();
  }

  friend std::istream& operator>>(std::istream& in, ModNum& lhs) {
    int64_t _v;
    in >> _v;
    lhs = ModNum(_v);
    return lhs;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  using Z = ModNum<998244353>;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
      std::cin >> b[i];
    }
    std::vector<Z> dp(2, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 1; i < n; ++i) {
      std::vector<Z> ndp(2, 0);
      for (int x = 0; x < 2; ++x) {
        for (int y = 0; y < 2; ++y) {
          int a1 = a[i - 1];
          int b1 = b[i - 1];
          int a2 = a[i];
          int b2 = b[i];
          if (x) {
            std::swap(a1, b1);
          }
          if (y) {
            std::swap(a2, b2);
          }
          if (a1 <= a2 && b1 <= b2) {
            ndp[y] += dp[x];
          }
        }
      }
      std::swap(dp, ndp);
    }
    std::cout << dp[0] + dp[1] << "\n";
  }

  return 0;
}
