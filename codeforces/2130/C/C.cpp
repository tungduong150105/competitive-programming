#include "bits/stdc++.h"

struct DSU {
  bool small_to_large = true;
  std::vector<int> f;

  DSU() {}
  DSU(int n, bool _small_to_large = false) {
    init(n, _small_to_large);
  }

  void init(int n, bool _small_to_large) {
    f.assign(n, -1);
    small_to_large = _small_to_large;
  }
  int leader(int x) {
    if (f[(size_t) x] < 0) {
      return x;
    }
    return f[x] = leader(f[x]);
  }
  int size(int x) {
    return -f[leader(x)];
  }
  bool same(int u, int v) {
    return leader(u) == leader(v);
  }
  bool merge(int u, int v) {
    u = leader(u), v = leader(v);
    if (u == v) {
      return false;
    }
    if (small_to_large && f[u] > f[v]) {
      std::swap(u, v);
    }
    f[u] += f[v];
    f[v] = u;
    return true;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T; std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n; std::cin >> n;

    DSU dsu(2 * n);
    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
      int a, b; std::cin >> a >> b;
      --a, --b;
      if (dsu.merge(a, b)) {
        ans.push_back(i + 1);
      }
    }

    std::cout << (int) ans.size() << "\n";
    for (auto v : ans) {
      std::cout << v << " \n"[v == ans.back()];
    }
  }

  return 0;
}
