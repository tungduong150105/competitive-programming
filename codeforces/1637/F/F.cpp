#include "bits/stdc++.h"

namespace std {
template <class Fun>
class y_combinator_result {
  Fun fun_;

 public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {
  }

  template <class... Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template <class Fun>
decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
}  // namespace std

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> h[i];
  }

  std::vector<std::vector<int>> adj(n);
  for (int j = 0; j < n - 1; ++j) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int64_t ans = 0;
  int max_idx = std::max_element(h.begin(), h.end()) - h.begin();
  std::y_combinator([&](auto self, int u, int p) -> int {
    int mx0 = 0, mx1 = 0;
    for (int v : adj[u]) {
      if (v == p) {
        continue;
      }
      int mx = self(v, u);
      if (mx > mx0) {
        std::swap(mx0, mx);
      }
      if (mx > mx1) {
        std::swap(mx1, mx);
      }
    }
    if (p != -1) {
      int diff = std::max(0, h[u] - mx0);
      ans += diff;
      mx0 += diff;
    } else {
      ans += std::max(0, h[u] - mx0) + std::max(0, h[u] - mx1);
    }
    return mx0;
  })(max_idx, -1);

  std::cout << ans << "\n";

  return 0;
}
