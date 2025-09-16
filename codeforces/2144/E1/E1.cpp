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
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    auto f = [&]() {
      std::vector<int> g;
      for (int i = 0; i < n; ++i) {
        if (g.empty() || a[i] > g.back()) {
          g.push_back(a[i]);
        }
      }
      int m = int(g.size());
      std::vector dp(n + 1, std::vector<Z> (m + 1, 0));
      dp[0][0] = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          dp[i + 1][j] += dp[i][j];
        }
        for (int j = 0; j < m; ++j) {
          if (j && a[i] <= g[j - 1]) {
            dp[i + 1][j] += dp[i][j];
          }
          if (a[i] == g[j]) {
            dp[i + 1][j + 1] += dp[i][j];
          }
        }
      }
      std::vector<Z> ans;
      for (int i = 1; i <= n; ++i) {
        ans.push_back(dp[i][m]);
      }
      return ans;
    };
    auto pref = f();
    std::reverse(a.begin(), a.end());
    auto suff = f();
    std::reverse(suff.begin(), suff.end());
    std::reverse(a.begin(), a.end());
    int mx = *std::max_element(a.begin(), a.end());
    Z ans = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == mx) {
        for (int j = i; j < n; ++j) {
          if (a[j] == mx) {
            ans += pref[i] * suff[j] * power(Z(2), std::max(0, j - i - 1));
            // std::cout << i + 1 << " " << j + 1 << " " << pref[i] << " " << suff[j] << " " << power(Z(2), std::max(0, j - i - 1)) << "\n";
          }
        }
      }
    }
    std::cout << ans << "\n";
  }

  return 0;
}
