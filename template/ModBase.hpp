template <typename T> T mod_inv_in_range(T a, T m) {
	// assert(0 <= a && a < m);
	T x = a, y = m;
	// coeff of a in x and y
	T vx = 1, vy = 0;
	while (x) {
		T k = y / x;
		y %= x;
		vy -= k * vx;
		std::swap(x, y);
		std::swap(vx, vy);
	}
	assert(y == 1);
	return vy < 0 ? m + vy : vy;
}

template <typename T> struct extended_gcd_result {
	T gcd;
	T coeff_a, coeff_b;
};
template <typename T> extended_gcd_result<T> extended_gcd(T a, T b) {
	T x = a, y = b;
	// coeff of a and b in x and y
	T ax = 1, ay = 0;
	T bx = 0, by = 1;
	while (x) {
		T k = y / x;
		y %= x;
		ay -= k * ax;
		by -= k * bx;
		std::swap(x, y);
		std::swap(ax, ay);
		std::swap(bx, by);
	}
	return {y, ay, by};
}

template <typename T> T mod_inv(T a, T m) {
	a %= m;
	a = a < 0 ? a + m : a;
	return mod_inv_in_range(a, m);
}

template <int MOD_> struct ModBase {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");
private:
	int v;
public:
	ModBase() : v(0) {}
	ModBase(int64_t v_) : v(int(v_ % MOD)) {
		if (v < 0) v += MOD;
	}
	explicit operator int() const {
		return v;
	}
	friend std::ostream& operator << (std::ostream& out, const ModBase& n) {
		return out << int(n);
	}
	friend std::istream& operator >> (std::istream& in, ModBase& n) {
		int64_t v_; in >> v_; n = ModBase(v_);
		return in;
	}
	friend bool operator == (const ModBase& a, const ModBase& b) {
		return a.v == b.v;
	}
	friend bool operator != (const ModBase& a, const ModBase& b) {
		return a.v != b.v;
	}
	ModBase inv() const {
		ModBase res;
		res.v = mod_inv_in_range(v, MOD);
		return res;
	}
	friend ModBase inv(const ModBase& m) {
		return m.inv();
	}
	ModBase neg() const {
		ModBase res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend ModBase neg(const ModBase& m) {
		return m.neg();
	}
	ModBase operator- () const {
		return neg();
	}
	ModBase operator+ () const {
		return ModBase(*this);
	}
	ModBase& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	ModBase& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	ModBase& operator += (const ModBase& o) {
		v -= MOD-o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	ModBase& operator -= (const ModBase& o) {
		v -= o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	ModBase& operator *= (const ModBase& o) {
		v = int(int64_t(v) * int64_t(o.v) % MOD);
		return *this;
	}
	ModBase& operator /= (const ModBase& o) {
		return *this *= o.inv();
	}

	friend ModBase operator ++ (ModBase& a, int) {
		ModBase r = a; ++a; return r;
	}
	friend ModBase operator -- (ModBase& a, int) {
		ModBase r = a; --a;
		return r;
	}
	friend ModBase operator + (const ModBase& a, const ModBase& b) {
		return ModBase(a) += b;
	}
	friend ModBase operator - (const ModBase& a, const ModBase& b) {
		return ModBase(a) -= b;
	}
	friend ModBase operator * (const ModBase& a, const ModBase& b) {
		return ModBase(a) *= b;
	}
	friend ModBase operator / (const ModBase& a, const ModBase& b) {
		return ModBase(a) /= b;
	}
};

using Z = ModBase<998244353>;

template <typename T> T power(T a, long long b) {
	assert(b >= 0);
	T r = 1;
	while (b) {
		if (b & 1) r *= a; b >>= 1; a *= a;
	}
	return r;
}