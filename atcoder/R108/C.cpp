#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<array<int, 2>>> adj(n + 5);
    vector<int> vis(n + 5);
    for (int i = 0, u, v, c; i < m; i++) {
        cin >> u >> v >> c;
        adj[u].push_back({ v, c });
        adj[v].push_back({ u, c });
    }

    function<void(int)> dfs = [&](int u) {
        for (auto x : adj[u]) {
            int v = x[0], c0 = x[1];
            if (vis[v]) continue;
            if (c0 == vis[u]) vis[v] = c0 == 1 ? 2 : 1;
            else vis[v] = c0;
            dfs(v);
        }
    };

    vis[1] = 1;
    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "No\n";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) cout << vis[i] << "\n";

    return 0;
}
