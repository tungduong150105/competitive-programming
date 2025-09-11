#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T; std::cin >> T;
  for (int case_num = 0; case_num < T; ++case_num) {
    int n, s; std::cin >> n >> s;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }

    int sum = std::accumulate(a.begin(), a.end(), 0);
    if (sum > s || sum == s - 1) {
      std::sort(a.begin(), a.end(), [&](int i, int j) {
        return (3 - i) % 3 < (3 - j) % 3;
      });
      for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " \n"[i == n - 1];
      }
    } else {
      std::cout << "-1\n";
    }
  }

  return 0;
}
