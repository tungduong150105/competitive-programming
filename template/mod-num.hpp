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

using Z = ModNum<998244353>;