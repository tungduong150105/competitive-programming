#include "bits/stdc++.h"

template <typename T>
struct FenwickTree {
  int n;
  std::vector<T> a;
  FenwickTree() : n(0) {}
  FenwickTree(int _n) {
    init(_n);
  }
  void init(int _n) {
    n = _n;
    a.assign(n, T());
  }
  void add(int x, const T &v) {
    for (int i = x + 1; i <= n; i += i & -i) {
      a[i - 1] = a[i - 1] + v;
    }
  }
  T sum(int x) {
    T ans{};
    for (int i = x; i > 0; i -= i & -i) {
      ans = ans + a[i - 1];
    }
    return ans;
  }
  T rangeSum(int l, int r) {
    return sum(r) - sum(l);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T = 1;
  // // std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n, q; std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    FenwickTree<int64_t> fen(n);
    for (int i= 0; i < q; ++i) {
      int cmd; std::cin >> cmd;
      if (cmd == 1) {
        int l, r, v; std::cin >> l >> r >> v;
        fen.add(l - 1, v);
        fen.add(r, -v);
      } else {
        int k; std::cin >> k;
        std::cout << fen.sum(k) + a[k - 1] << "\n";
      }
    }
  }

  return 0;
}
