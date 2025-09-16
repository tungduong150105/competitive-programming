#include <bits/stdc++.h>

template <class T, class Merge = std::plus<T>>
struct SegmentTree {
  int n;
  Merge merge;
  std::vector<T> data;

  SegmentTree(int m = 0) : merge(Merge()) {
    init(m);
  }

  SegmentTree(const std::vector<T>& init) : SegmentTree(int(init.size())) {
    std::function<void(int, int, int)> build = [&](int p, int l, int r) {
      if (r - l == 1) {
        data[p] = init[l];
        return;
      }
      int m = (l + r) / 2;
      build(2 * p, l, m);
      build(2 * p + 1, m, r);
      push(p);
    };
    build(1, 0, n);
  }

  void init(int m) {
    n = m;
    data.assign(4 << std::__lg(n), T());
  }

  void push(int p) {
    data[p] = merge(data[2 * p], data[2 * p + 1]);
  }

  void modify(int p, int l, int r, int x, T v) {
    if (r - l == 1) {
      data[p] = v;
      return;
    }
    int m = (l + r) / 2;
    if (x < m) {
      modify(2 * p, l, m, x, v);
    } else {
      modify(2 * p + 1, m, r, x, v);
    }
    push(p);
  }

  void modify(int x, T v) {
    modify(1, 0, n, x, v);
  }

  T rangeQuery(int p, int l, int r, int x, int y) {
    if (l >= y || r <= x) {
      return T();
    }
    if (x <= l && r <= y) {
      return data[p];
    }
    int m = (l + r) / 2;
    return merge(rangeQuery(2 * p, l, m, x, y), rangeQuery(2 * p + 1, m, r, x, y));
  }

  T rangeQuery(int l, int r) {
    return rangeQuery(1, 0, n, l, r);
  }
};

struct Op {
  int64_t operator()(const int64_t& lhs, const int64_t& rhs) const {
    return std::max(lhs, rhs);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n;
    std::cin >> n;
    std::vector<int> all;
    std::vector<std::tuple<int, int, int>> info;
    for (int i = 0; i < n; ++i) {
      int a, b, h;
      std::cin >> a >> b >> h;
      all.push_back(a);
      all.push_back(b);
      info.emplace_back(a, b, h);
    }
    std::sort(all.begin(), all.end());
    all.erase(std::unique(all.begin(), all.end()), all.end());
    for (auto& [a, b, h] : info) {
      a = std::lower_bound(all.begin(), all.end(), a) - all.begin();
      b = std::lower_bound(all.begin(), all.end(), b) - all.begin();
    }
    std::sort(info.begin(), info.end(), [&](const auto& lhs, const auto& rhs) {
      if (std::get<1>(lhs) == std::get<1>(rhs)) {
        return std::get<0>(lhs) > std::get<0>(rhs);
      }
      return std::get<1>(lhs) > std::get<1>(rhs);
    });
    SegmentTree<int64_t, Op> seg(int(all.size()) + 1);
    seg.modify(0, 0);
    for (auto [a, b, h] : info) {
      int64_t mx = h + seg.rangeQuery(0, b);
      int64_t mx_a = seg.rangeQuery(a, a + 1);
      seg.modify(a, std::max(mx_a, mx));
    }
    std::cout << seg.rangeQuery(0, int(all.size()) + 1) << "\n";
  }

  return 0;
}
