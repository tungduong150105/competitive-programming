#include "bits/stdc++.h"

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
	void mod_range(int v, int l, int r, int lhs, int rhs, int Mod) {
		if (lhs >= r || rhs <= l || tree[v].max < Mod) return;
		if (lhs <= l && r <= rhs && r - l == 1) {
			tree[v].max %= Mod;
			tree[v].sum %= Mod;
			return;
		}
		int m = (l + r) >> 1;
		mod_range(v << 1, l, m, lhs, rhs, Mod);
		mod_range(v << 1 | 1, m, r, lhs, rhs, Mod);
		tree[v] = tree[v << 1] + tree[v << 1 | 1];
	}
	void mod_range(int l, int r, int Mod) {
		mod_range(1, 0, n, l, r, Mod);
	}
};
 
struct Info {
	int64_t sum = 0, max = 0;
};
 
Info operator+(const Info &lhs, const Info &rhs) {
	return Info{lhs.sum + rhs.sum, std::max(lhs.max, rhs.max)};
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int n, m; std::cin >> n >> m;
	SegTree<Info> seg(n);
	for (int i = 0; i < n; ++i) {
		int x; std::cin >> x;
		seg.modify(i, Info{x, x});
	}
	while (m--) {
		int type; std::cin >> type;
		if (type == 1) {
			int l, r; std::cin >> l >> r;
			std::cout << seg.range_query(l - 1, r).sum << "\n";
		} else if (type == 2) {
			int l, r, x; std::cin >> l >> r >> x;
			seg.mod_range(l - 1, r, x);
		} else {
			int k, x; std::cin >> k >> x;
			seg.modify(k - 1, {x, x});
		}
	}
	return 0;
}
