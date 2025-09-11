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
  
  int n; std::cin >> n;

  DSU dsu(n);
  std::vector<std::pair<int, int>> rem;
  for (int i = 0; i < n - 1; ++i) {
    int u, v; std::cin >> u >> v;
    --u, --v;
    if (!dsu.merge(u, v)) {
      rem.emplace_back(u, v);
    }
  }

  std::cout << int(rem.size()) << "\n";
  std::set<int> ans;
  for (int i = 0; i < n; ++i) {
    ans.insert(dsu.leader(i));
  }

  auto s = ans.begin();
  for (int i = 0; i < int(ans.size()) - 1; ++i) {
    std::cout << rem[i].first + 1 << " " << rem[i].second + 1 << " " << *s++ + 1 << " " << *s + 1 << "\n";
  }

  return 0;
}
