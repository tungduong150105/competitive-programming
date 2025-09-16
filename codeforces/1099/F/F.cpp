#include "bits/stdc++.h"

namespace std {
template <class Fun>
class y_combinator_result {
  Fun fun_;

 public:
  template <class T>
  explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {
  }

  template <class... Args>
  decltype(auto) operator()(Args&&... args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template <class Fun>
decltype(auto) y_combinator(Fun&& fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
}  // namespace std

template <typename T>
struct FenwickTree {
  int n;
  std::vector<T> a;

  FenwickTree(int m = 0) {
    init(m);
  }
  
  void init(int m) {
    n = m;
    a.resize(m, T());
  }

  void add(int p, T v) {
    for (int i = p + 1; i <= n; i += i & -i) {
      a[i - 1] += v;
    }
  }

  T sum(int p) {
    T ans = T();

    for (int i = p; i > 0; i -= i & -i) {
      ans += a[i - 1];
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

  int TT = 1;
  // std::cin >> T;

  for (int case_num = 0; case_num < TT; ++case_num) {
    int n;
    int64_t T;
    std::cin >> n >> T;
    std::vector<int> x(n);

    for (int i = 0; i < n; ++i) {
      std::cin >> x[i];
    }

    std::vector<int> t(n);

    for (int i = 0; i < n; ++i) {
      std::cin >> t[i];
    }

    std::vector<int64_t> l(n, 0);
    std::vector<std::vector<int>> adj(n);

    for (int i = 1; i < n; ++i) {
      int P, L;
      std::cin >> P >> L;
      --P;
      l[i] = L;
      adj[P].push_back(i);
    }
    FenwickTree<int64_t> fens(1000005), fenc(1000005);
    std::vector<int64_t> f(n, 0);

    std::y_combinator([&](auto self, int u, int p) -> void {
      fens.add(t[u], 1LL * t[u] * x[u]);
      fenc.add(t[u], x[u]);

      for (int v : adj[u]) {
        if (v == p) {
          continue;
        }

        l[v] += l[u];
        self(v, u);
      }
      int64_t rem = T - 2LL * l[u];

      if (rem > 0) {
        int lo = 1, hi = 1000005;

        while (hi - lo > 1) {
          int mid = (lo + hi) / 2;

          if (fens.sum(mid) <= rem) {
            lo = mid;
          } else {
            hi = mid;
          }
        }

        int64_t rem2 = rem - fens.sum(lo);
        int64_t tot = fenc.sum(lo);

        if (fenc.rangeSum(lo, lo + 1)) {
          int64_t sum_n = fens.rangeSum(lo, lo + 1);
          int64_t count_n = fenc.rangeSum(lo, lo + 1);
          int64_t each_t = sum_n / count_n;
          tot += rem2 / each_t;
        }

        f[u] = tot;
      }
      fens.add(t[u], -1LL * t[u] * x[u]);
      fenc.add(t[u], -x[u]);
    })(0, -1);
    std::vector<int64_t> dp(n, 0);
    std::y_combinator([&](auto self, int u, int p) -> void {
      int64_t mx = 0, mx2 = 0;

      for (int v : adj[u]) {
        if (v == p) {
          continue;
        }

        self(v, u);

        if (dp[v] > mx) {
          mx2 = mx;
          mx = dp[v];
        } else if (dp[v] > mx2) {
          mx2 = dp[v];
        }
      }
      dp[u] = std::max(f[u], mx2);

      if (u == 0) {
        dp[u] = std::max(dp[u], mx);
      }
    })(0, -1);

    // for (int i = 0; i < n; ++i) {
    //   std::cout << f[i] << " \n"[i == n - 1];
    // }
    std::cout << dp[0] << "\n";
  }

  return 0;
}
