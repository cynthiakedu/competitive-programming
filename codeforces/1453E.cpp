#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 5);
        for (int i = 0, x, y; i < n - 1; i++) {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> vis(n + 5);
        int k = 0;
        function<void(int, int)> dfs = [&](int u, int p) {
            vector<int> vals;
            for (int v : adj[u]) {
                if (v == p) continue;
                dfs(v, u);
                vals.push_back(vis[v]);
            }
            sort(vals.begin(), vals.end());
            int sz = (int)vals.size();
            vis[u] = 1 + (sz ? vals[0] : 0);
            for (int i = 0; i < sz - 1; i++) k = max(k, vals[i] + 1);
            if (u != 1 && sz) k = max(k, vals[sz - 1] + 1);
            if (u == 1 && sz) k = max(k, vals[sz - 1]);
        };
        dfs(1, -1);
        cout << k << "\n";
    }

    return 0;
}
