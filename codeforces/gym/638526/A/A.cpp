#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) std::cin >> s[i];
    std::vector<std::set<int>> adj(26);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int cnt = 0;
            for (int l = 0; l < std::min(int(s[i].size()), int(s[j].size())); ++l) {
                cnt += s[i][l] == s[j][l];
                if (s[i][l] == s[j][l]) continue;
                adj[s[i][l] - 'a'].insert(s[j][l] - 'a');
                break;
            }
            int lf = int(s[i].size()), rt = int(s[j].size());
            if (rt == cnt && lf > rt) {
                std::cout << "Impossible\n";
                return 0;
            }
        }
    }
    std::vector<int> vis(26, false), topo;
    auto dfs = [&](auto &self, int u) -> void {
        for (int v : adj[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            self(self, v);
        }
        topo.push_back(u);
    };
    for (int i = 0; i < 26; ++i) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(dfs, i);
        }
    }
    std::reverse(topo.begin(), topo.end());
    std::string ans = std::string(26, 'a');
    for (int i = 0; i < 26; ++i) ans[topo[i]] = char(i + 'a');
    bool valid = true;
    for (int i = 0; i < 26; ++i) {
        for (int v : adj[i]) {
            if (ans[v] < ans[i]) valid = false;
        }
    }
    if (valid) {
        std::vector<int> p(26);
        std::iota(p.begin(), p.end(), 0);
        std::sort(p.begin(), p.end(), [&](const auto &lhs, const auto &rhs) { return ans[lhs] < ans[rhs]; });
        for (int v : p) std::cout << char(v + 'a');
        std::cout << "\n";
    } else {
        std::cout << "Impossible\n";
    }
    return 0;
}
