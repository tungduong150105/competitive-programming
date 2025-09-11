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
  template<class Fun>
  decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
  }
} // namespace std

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n; std::cin >> n;
  std::vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> c[i];
  }

  int root = 0;
  std::vector<std::vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; std::cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    if (root == -1) {
      root = u;
    }
  }

  std::vector<int> cmx(n);
  std::vector<std::set<std::pair<int, int>>> value(n);
  std::vector<int64_t> dom(n, 0);
  std::y_combinator([&](auto self, int u, int p) -> void {
    cmx[u] = 1;
    dom[u] += c[u];
    value[u].insert(std::make_pair(c[u], 1));
    for (int v : adj[u]) {
      if (v == p) {
        continue;
      }
      self(v, u);
      if (int(value[v].size()) > int(value[u].size())) {
        std::swap(value[u], value[v]);
        std::swap(cmx[u], cmx[v]);
        dom[u] = dom[v];
      }
      for (auto [_u, _cnt] : value[v]) {
        auto it = value[u].lower_bound(std::make_pair(_u, 0));
        if ((*it).first == _u) {
          auto it_value = *it;
          value[u].erase(it_value);
          value[u].insert(std::make_pair(_u, it_value.second + _cnt));
          if (it_value.second + _cnt > cmx[u]) {
            cmx[u] = it_value.second + _cnt;
            dom[u] = _u;
          } else if (it_value.second + _cnt == cmx[u]) {
            dom[u] += _u;
          }
        } else {
          value[u].insert(std::make_pair(_u, _cnt));
          if (_cnt > cmx[u]) {
            cmx[u] = _cnt;
            dom[u] = _u;
          } else if (_cnt == cmx[u]) {
            dom[u] += _u;
          }
        }
      }
    }
  })(root, -1);

  for (int i = 0; i < n; ++i) {
    std::cout << dom[i] << " \n"[i == n - 1];
  }

  return 0;
}
