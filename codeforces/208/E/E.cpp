#include "bits/stdc++.h"

namespace std {
template <class Fun>
class y_combinator_result {
  Fun fun_;
public:
  template<class T>
  explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
  template<class ...Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
} // namespace std

template <typename T>
struct FenwickTree {
  int n;
  std::vector<T> a;
  FenwickTree(int m = 0) {
    init(m);
  }
  void init(int m) {
    n = m;
    a.assign(m, T());
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

  int T = 1;
  // std::cin >> T;

  for (int case_num = 0; case_num < T; ++case_num) {
    int n;
    std::cin >> n;

    std::vector<int> root;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
      int p;
      std::cin >> p;

      if (p != 0) {
        adj[p - 1].push_back(i);
      } else {
        root.push_back(i);
      }
    }

    constexpr int LOG = 20;
    int timer = 0;
    std::vector<int> in(n, 0), ot(n, 0);
    std::vector<int> dep(n, 0);
    std::vector up(n, std::vector<int> (LOG + 1, -1));
    std::vector<int> g;

    for (int _u : root) {
      std::y_combinator([&](auto self, int u, int p) -> void {
        in[u] = timer++;
        g.push_back(dep[u]);

        for (int v : adj[u]) {
          if (v == p) {
            continue;
          }

          dep[v] = dep[u] + 1;
          up[v][0] = u;

          for (int i = 1; i < LOG; ++i) {
            if (up[v][i - 1] == -1) {
              continue;
            }

            up[v][i] = up[up[v][i - 1]][i - 1];
          }

          self(v, u);
        }
        ot[u] = timer;
      })(_u, -1);
    }

    auto kth = [&](int u, int k) -> int {
      if (k > dep[u]) {
        return -1;
      }
      for (int i = LOG - 1; i >= 0; --i) {
        if (k >> i & 1) {
          assert(up[u][i] != -1);
          u = up[u][i];
        }
      }
      return u;
    };

    int m;
    std::cin >> m;

    std::vector<std::array<int, 3>> queries_add, queries_del;
    for (int i = 0; i < m; ++i)  {
      int v, p;
      std::cin >> v >> p;
      --v;
      int unc = kth(v, p);

      if (unc != -1) {
        queries_add.push_back({ot[unc], dep[unc] + p, i});
        queries_del.push_back({in[unc], dep[unc] + p, i});
      }
    }
    std::sort(queries_add.begin(), queries_add.end());
    std::sort(queries_del.begin(), queries_del.end());
    std::vector<int> ans(m, 0);
    FenwickTree<int> fenw(n + 1);
    int l = 0, r = -1;

    for (auto [_r, p, idx] : queries_add) {
      while (r < _r) {
        fenw.add(g[++r], 1);
      }

      ans[idx] += fenw.rangeSum(p, p + 1) - 1;
    }
    fenw.init(n + 1);

    for (auto [_l, p, idx] : queries_del) {
      while (l < _l) {
        fenw.add(g[l++], 1);
      }

      ans[idx] -= fenw.rangeSum(p, p + 1);
    }
    for (int i = 0; i < m; ++i) {
      std::cout << ans[i] << " \n"[i == m - 1];
    }
  }

  return 0;
}
