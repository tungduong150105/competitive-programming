#include "bits/stdc++.h"

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

template <class Info, class Tag> struct SegLazy {
	int n;
	std::vector<Info> tree;
	std::vector<Tag> lazy;
	SegLazy() {}
	SegLazy(int _n) {
		init(_n);
	}
	void init(int _n) {
		n = _n;
		tree.assign(4 * n, Info());
		lazy.assign(4 * n, Tag());
	}
	void apply(int v, int l, int r, const Tag &x) {
		tree[v].apply(x, l, r);
		lazy[v].apply(x);
	}
	void push_down(int v, int l, int r) {
		int m = (l + r) >> 1;
		apply(v << 1, l, m, lazy[v]);
		apply(v << 1 | 1, m, r, lazy[v]);
		lazy[v] = Tag();
	}
	void modify(int v, int l, int r, int idx, const Info &x) {
		if (r - l == 1) {
			tree[v] = tree[v] + x;
			return;
		}
		int m = (l + r) / 2;
		push_down(v, l, r);
		if (idx < m) {
			modify(v << 1, l, m, idx, x);
		} else {
			modify(v << 1 | 1, m, r, idx, x);
		}
		tree[v] = tree[v << 1] + tree[v << 1 | 1];
	}
	void range_update(int v, int l, int r, int lhs, int rhs, const Tag &x) {
		if (rhs <= l || lhs >= r) return;
		if (lhs <= l && r <= rhs) {
			apply(v, l, r, x);
		} else {
			push_down(v, l, r);
			int m = (l + r) >> 1;
			range_update(v << 1, l, m, lhs, rhs, x);
			range_update(v << 1 | 1, m, r, lhs, rhs, x);
			tree[v] = tree[v << 1] + tree[v << 1 | 1];
		}
	}
	Info range_query(int v, int l, int r, int lhs, int rhs) {
		if (rhs <= l || lhs >= r) return Info();
		if (lhs <= l && r <= rhs) return tree[v];
		push_down(v, l, r);
		int m = (l + r) >> 1;
		return range_query(v << 1, l, m, lhs, rhs) + range_query(v << 1 | 1, m, r, lhs, rhs);
	}
	void modify(int idx, const Info &x) {
		modify(1, 0, n, idx, x);
	}
	void range_update(int l, int r, const Tag &x) {
		range_update(1, 0, n, l, r, x);
	}
	Info range_query(int l, int r) {
		return range_query(1, 0, n, l, r);
	}
};
 
struct Tag {
	Z val = 1;
	void apply(const Tag &t) {
		val *= t.val;
	}
};
 
struct Info {
	Z val = 0;
	void apply(const Tag &t, int l, int r) {
		val *= t.val;
	}
};
 
Info operator+(const Info &lhs, const Info &rhs) {
	return {lhs.val + rhs.val};
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int t; std::cin >> t;
	while (t--) {
		int n; std::cin >> n;
		std::vector<int> a(n);
		for (int i = 0; i < n; ++i) std::cin >> a[i];
		auto f = [&]() -> std::vector<Z> {
			std::vector<int> vec;
			for (int i = 0; i < n; ++i) {
				if (vec.empty() || a[i] > vec.back()) vec.push_back(a[i]);
			}
			std::vector<Z> ans;
			int m = int(vec.size());
			SegLazy<Info, Tag> seglz(m + 1);
			seglz.modify(0, Info{1});
			// for (int i = 0; i <= m; ++i) std::cout << seglz.range_query(i, i + 1).val << " \n"[i == m];
			for (int i = 0; i < n; ++i) {
				int l = std::lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
				if (l < m - 1) seglz.range_update(l + 1, m, Tag{2});
				if (a[i] == vec[l] && l < m - 1) seglz.modify(l + 1, Info{seglz.range_query(l, l + 1).val});
				if (a[i] == vec[l] && l == m - 1) {
					ans.push_back(seglz.range_query(m - 1, m).val);
				} else {
					ans.push_back(0);
				}
				// for (int j = 0; j <= m; ++j) {
				// 	std::cout << seglz.range_query(j, j + 1).val << " \n"[j == m];
				// }
			}
			return ans;
		};
		auto lf = f();
		std::reverse(a.begin(), a.end());
		auto rt = f();
		std::reverse(rt.begin(), rt.end());
		std::reverse(a.begin(), a.end());
		// for (auto v : lf) std::cout << v << " ";
		// std::cout << "\n";
		// for (auto v : rt) std::cout << v << " ";
		// std::cout << "\n";
		Z ans = 0, suff = 0;
		int mx = *std::max_element(a.begin(), a.end());
		for (int i = n - 1; i >= 0; --i) suff *= 2, suff += rt[i];
		// std::cout << suff << " ";
		for (int i = 0; i < n; ++i) {
			suff -= rt[i];
			suff /= 2;
			Z tot = suff + rt[i];
			ans += lf[i] * tot;
			// if (a[i] == mx) std::cout << lf[i] << " " << tot << "\n";
			// std::cout << lf[i] << " " << tot << " " << rt[i] << "\n";
		}
		std::cout << ans << "\n";
	}
	return 0;
}

// for (i = 1 -> n)
// 	for (j = i -> n)
// 	 if (a[i] == a[j] && a[i] == mx) ans += lf[i] * rt[j] * 2 ^ max(0, j - i - 1);

// for (i = 1 -> n) ans += lf[i] * sigma(rt[j] * 2 ^ max(0, j - i - 1))

