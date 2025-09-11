#include "bits/stdc++.h" 

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k; std::cin >> n >> k;
  std::vector<std::pair<int, int>> a;
  for (int i = 0; i < n; ++i) {
    int l, r; std::cin >> l >> r;
    a.emplace_back(l, r);
  }

  std::vector<int> p(n);
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin(), p.end(), [&](int i, int j) {
    return a[i] < a[j];
  });

  std::vector<int> ans;
  std::vector<int> s(200005, 0);
  std::set<std::pair<int, int>> cur;
  for (int i = 1, j = 0; i < 200001; ++i) {
    s[i] += s[i - 1];
    while (j < n && a[p[j]].first <= i) {
      cur.insert(std::make_pair(a[p[j]].second, p[j]));
      ++s[i];
      --s[a[p[j]].second + 1];
      ++j;
    }
    while (s[i] > k) {
      --s[i];
      auto last = *--cur.end();
      cur.erase(last);
      ans.push_back(last.second + 1);
      ++s[last.first + 1];
    }
  }

  std::sort(ans.begin(), ans.end());
  std::cout << int(ans.size()) << "\n";
  for (int v : ans) {
    std::cout << v << " \n"[v == ans.back()];
  }

  return 0;
}
