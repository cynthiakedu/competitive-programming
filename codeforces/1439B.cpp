#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<unordered_set<int>> adj(N + 5);
    vector<bool> r(N + 5);
    queue<int> q;


    for (int m = 0, x, y; m < M; m++) {
        cin >> x >> y;
        adj[x].insert(y), adj[y].insert(x);
    }
    if (K > sqrt(2 * M) + 1) {
        cout << -1 << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (adj[i].size() < K) {
            r[i] = true;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        //check clique
        if (adj[u].size() == K - 1) {
            bool ok = true;
            vector<int> v(adj[u].begin(), adj[u].end());
            for (int a = 0; a < (int)v.size(); a++) {
                for (int b = a + 1; b < (int)v.size(); b++) {
                    if (!adj[v[a]].count(v[b])) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                cout << 2 << "\n";
                v.push_back(u);
                for (int i = 0; i < (int)v.size(); i++) {
                    cout << v[i] << (i == (int)v.size() - 1 ? "\n" : " ");
                }
                return;
            }
        }

        //remove edges
        for (int v : adj[u]) {
            adj[v].erase(u);
            if (adj[v].size() < K && !r[v]) {
                r[v] = true;
                q.push(v);
            }
        }
        adj[u].clear();
    }

    vector<int> v;
    for (int i = 1; i <= N; i++) {
        if (!r[i]) v.push_back(i);
    }
    if (v.size() == 0) {
        cout << -1 << "\n";
        return;
    }
    cout << 1 << " " << v.size() << "\n";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << (i == (int)v.size() - 1 ? "\n" : " ");
    }
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}