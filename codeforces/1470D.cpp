#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t; cin >> t;
    while (t--) {
        []() {
            int n, m;
            cin >> n >> m;
            vector<vector<int>> adj(n + 5);
            for (int i = 1, x, y; i <= m;i++) {
                cin >> x >> y;
                adj[x].push_back(y);
                adj[y].push_back(x);
            }

            set<int> canChoose; canChoose.insert(1);
            vector<int> vis(n + 5, 0);
            while ((int)canChoose.size()) {
                int u = *canChoose.begin();
                canChoose.erase(u);
                vis[u] = 1;
                for (int x : adj[u]) if (!vis[x]) {
                    vis[x] = 2;
                    for (int y : adj[x]) {
                        if (vis[y]) continue;
                        canChoose.insert(y);
                    }
                }
                for (int x : adj[u]) {
                    if (canChoose.count(x)) {
                        canChoose.erase(x);
                    }
                }
            }
            vector<int> ans;
            for (int i = 1; i <= n; i++) {
                if (!vis[i]) {
                    cout << "NO\n";
                    return;
                } else if (vis[i] == 1) {
                    ans.push_back(i);
                }
            }
            cout << "YES\n";
            cout << (int)ans.size() << "\n";
            for (int i = 0; i < (int)ans.size(); i++) {
                cout << ans[i] << (i == (int)ans.size() - 1 ? "\n" : " ");
            }
        }();
    }

    return 0;
}
