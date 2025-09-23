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