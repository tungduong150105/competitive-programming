#include "bits/stdc++.h"

template <class Info>
struct SegmentTree {
  int n;
  std::vector<Info> info;

  SegmentTree() : n(0) {
  }

  SegmentTree(int _n, Info _v = Info()) {
    init(_n, _v);
  }

  template <class T>
  SegmentTree(std::vector<T> _init) {
    init(_init);
  }

  void init(int _n, Info _v = Info()) {
    init(std::vector(_n, _v));
  }

  template <class T>
  void init(std::vector<T> _init) {
    n = _init.size();
    info.assign(4 << int(std::log2(n)), T());
    auto build = [&](auto& self, int p, int l, int r) -> void {
      if (r - l == 1) {
        info[p] = _init[l];
        return;
      }
      int m = (l + r) / 2;
      self(self, 2 * p, l, m);
      self(self, 2 * p + 1, m, r);
    };
    build(build, 1, 0, n);
  }

  void pull(int p) {
    info[p] = info[2 * p] + info[2 * p + 1];
  }

  void modify(int p, int l, int r, int x, const Info& v) {
    if (r - l == 1) {
      info[p] = v;
      return;
    }
    int m = (l + r) / 2;
    if (x < m) {
      modify(2 * p, l, m, x, v);
    } else {
      modify(2 * p + 1, m, r, x, v);
    }
    pull(p);
  }

  void modify(int x, const Info& v) {
    modify(1, 0, n, x, v);
  }

  Info rangeQuery(int p, int l, int r, int x, int y) {
    if (l >= y || r <= x) {
      return Info();
    }
    if (x <= l && r <= y) {
      return info[p];
    }
    int m = (l + r) / 2;
    return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
  }

  Info rangeQuery(int l, int r) {
    return rangeQuery(1, 0, n, l, r);
  }
};

struct Info {
  int64_t v = 0;
};

Info operator+(const Info& lhs, const Info& rhs) {
  return {lhs.v + rhs.v};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n, q;
    std::cin >> n >> q;
    SegmentTree<Info> seg(n);
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      seg.modify(i, {x});
    }
    for (int i = 0; i < q; ++i) {
      int l, r;
      std::cin >> l >> r;
      std::cout << seg.rangeQuery(l - 1, r).v << "\n";
    }
  }

  return 0;
}
