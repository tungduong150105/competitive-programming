#include "bits/stdc++.h"

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
		if (l <= lhs && rhs <= r) return tree[v];
		push_down(v, l, r);
		int m = (l + r) >> 1;
		return range_query(v << 1, l, m, lhs, rhs) + range_query(v << 1 | 1, m, r, lhs, rhs);
	}
	void range_update(int l, int r, const Tag &x) {
		range_update(1, 0, n, l, r, x);
	}
	Info range_query(int l, int r) {
		return range_query(1, 0, n, l, r);
	}
};

struct Tag {
	int type = 0, val = 0;
	void apply(const Tag &t) {
		if (t.type == 1) {
			val += t.val;
			if (type != 2) type = 1;
		} else if (t.type == 2) {
			type = 2;
			val = t.val;
		}
	}
};

struct Info {
	int val = 0;
	void apply(const Tag &t, int l, int r) {
		if (t.type == 2) {
			val = t.val;
		} else if (t.type == 1) {
			val += t.val;
		}
	}
};

Info operator+(const Info &lhs, const Info &rhs) {
	return {std::max(lhs.val, rhs.val)};
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int t; std::cin >> t;
	while (t--) {
		int n; std::cin >> n;
		SegLazy<Info, Tag> seglz(n + 1);
		for (int i = 0; i < n; ++i) {
			int x; std::cin >> x;
			seglz.range_update(0, x, {1, 1});
			seglz.range_update(x, x + 1, {2, 0});
			std::cout << seglz.range_query(0, n + 1).val << " \n"[i == n - 1];
		}
	}
	return 0;
}