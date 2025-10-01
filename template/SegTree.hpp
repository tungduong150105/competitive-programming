template <class Info> struct SegTree {
	int n;
	std::vector<Info> tree;
	SegTree() {}
	SegTree(int _n) {
		init(_n);
	}
	void init(int _n) {
		n = _n;
		tree.assign(4 * n, Info());
	}
	void modify(int v, int l, int r, int idx, const Info &x) {
		if (r - l == 1) {
			tree[v] = x;
			return;
		}
		int m = (l + r) / 2;
		if (idx < m) {
			modify(v << 1, l, m, idx, x);
		} else {
			modify(v << 1 | 1, m, r, idx, x);
		}
		tree[v] = tree[v << 1] + tree[v << 1 | 1];
	}
	Info range_query(int v, int l, int r, int lhs, int rhs) {
		if (rhs <= l || lhs >= r) return Info();
		if (lhs <= l && r <= rhs) return tree[v];
		int m = (l + r) >> 1;
		return range_query(v << 1, l, m, lhs, rhs) + range_query(v << 1 | 1, m, r, lhs, rhs);
	}
	void modify(int idx, const Info &x) {
		modify(1, 0, n, idx, x);
	}
	Info range_query(int l, int r) {
		return range_query(1, 0, n, l, r);
	}
};
 
struct Info {
	int64_t sum = 0, max = 0;
};
 
Info operator+(const Info &lhs, const Info &rhs) {
	return Info{lhs.sum + rhs.sum, std::max(lhs.max, rhs.max)};
}