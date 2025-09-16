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

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T = 1;
  // std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      std::cin >> u >> v;
      --u, --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int LOG = std::log2(n) + 1;
    std::vector up(n, std::vector<int>(LOG + 1, -1));
    std::vector<int> dep(n, 0);
    std::vector f(n, std::vector(LOG + 1, std::vector<int>()));
    for (int i = 0; i < m; ++i) {
      int c;
      std::cin >> c;
      --c;
      f[c][0].push_back(i);
      std::sort(f[c][0].begin(), f[c][0].end());
      if (int(f[c][0].size()) > 10) {
        f[c][0].pop_back();
      }
    }
    std::y_combinator([&](auto self, int u, int p) -> void {
      for (int v : adj[u]) {
        if (v == p) {
          continue;
        }
        dep[v] = dep[u] + 1;
        up[v][0] = u;
        for (int j = 1; j < LOG + 1; ++j) {
          if (up[v][j - 1] == -1) {
            continue;
          }
          up[v][j] = up[up[v][j - 1]][j - 1];
        }
        for (int j = 1; j < LOG + 1; ++j) {
          if (up[v][j - 1] == -1) {
            continue;
          }
          f[v][j] = f[v][j - 1];
          for (int x : f[up[v][j - 1]][j - 1]) {
            f[v][j].push_back(x);
          }
          std::sort(f[v][j].begin(), f[v][j].end());
          f[v][j].erase(std::unique(f[v][j].begin(), f[v][j].end()), f[v][j].end());
          while (int(f[v][j].size()) > 10) {
            f[v][j].pop_back();
          }
        }
        self(v, u);
      }
    })(0, -1);
    // std::cout << "---\n";
    // for (int v : f[4][1]) {
    //   std::cout << v << " ";
    // }
    // std::cout << "---\n";
    // for (int i = 0; i < n; ++i) {
    //   std::cout << "node " << i + 1 << ": " << dep[i] << "\n";
    // }
    auto lca = [&](int u, int v) -> int {
      if (dep[u] < dep[v]) {
        std::swap(u, v);
      }
      int diff = dep[u] - dep[v];
      for (int i = LOG; i >= 0; --i) {
        if (diff >> i & 1) {
          u = up[u][i];
        }
      }
      if (u == v) {
        return u;
      }
      for (int i = LOG; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
          u = up[u][i];
          v = up[v][i];
        }
      }
      return up[u][0];
    };
    while (q--) {
      int u, v, a;
      std::cin >> u >> v >> a;
      --u, --v;
      int comm = lca(u, v);
      // std::cout << comm << " " << u << " " << v << "\n";
      std::vector<int> ans;
      int diffu = dep[u] - dep[comm] + 1;
      // std::cout << "diff u: " << diffu << "\n";
      for (int i = LOG + 1; i >= 0; --i) {
        if (diffu >> i & 1) {
          for (int x : f[u][i]) {
            ans.push_back(x);
          }
          u = up[u][i];
        }
        std::sort(ans.begin(), ans.end());
        ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
        while (int(ans.size()) > 10) {
          ans.pop_back();
        }
      }
      // std::cout << "gg " << int(ans.size()) << " ";
      int diffv = dep[v] - dep[comm] + 1;
      // std::cout << "diffv: " << diffv << " ";
      for (int i = LOG + 1; i >= 0; --i) {
        if (diffv >> i & 1) {
          // std::cout << i << " ";
          for (int x : f[v][i]) {
            ans.push_back(x);
          }
          v = up[v][i];
        }
        std::sort(ans.begin(), ans.end());
        ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
        while (int(ans.size()) > 10) {
          ans.pop_back();
        }
      }
      // std::cout << "\n";
      // std::cout << "gg " << int(ans.size()) << " ";
      int cnt = std::min(int(ans.size()), a);
      std::cout << cnt << " ";
      for (int i = 0; i < cnt; ++i) {
        std::cout << ans[i] + 1 << " ";
      }
      std::cout << "\n";
    }
  }

  return 0;
}
