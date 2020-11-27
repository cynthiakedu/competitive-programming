#include <bits/stdc++.h>
using namespace std;
typedef array<int, 2> arr2;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int src, dest;
    cin >> src >> dest;
    int n, m;
    cin >> n >> m;
    vector<int> c(n + 5), rc(n + 5);
    vector<vector<int>> t(2, vector<int>(n + 5));
    for (int i = 1; i <= n; i++) {
        char c0;
        cin >> c0 >> rc[i] >> t[0][i] >> t[1][i];
        c[i] = (c0 == 'P' ? 1 : 0);
    }
    vector<vector<array<int, 2>>> adj(n + 5);
    for (int i = 0, u, v, tuv; i < m; i++) {
        cin >> u >> v >> tuv;
        adj[u].push_back({ v, tuv });
        adj[v].push_back({ u, tuv });
    }

    function<int(int, int)> getColor = [&](int u, int tu)->int {
        if (tu < rc[u]) return c[u];
        tu -= rc[u];
        tu = tu % (t[0][u] + t[1][u]);
        int fst = 1 - c[u];
        int res = tu < t[fst][u] ? fst : 1 - fst;
        return (tu < t[fst][u] ? fst : 1 - fst);
    };

    vector<int> par(n + 5);
    function<int(void)> dijkstra = [&]() -> int {
        priority_queue<arr2, vector<arr2>, greater<arr2>> pq;
        vector<int> dist(n + 5, INT_MAX);
        pq.push({ 0, src }), dist[src] = 0;

        while (!pq.empty()) {
            int u = pq.top()[1], d = pq.top()[0];
            pq.pop();
            if (d > dist[u]) continue;
            for (auto v : adj[u]) {
                int nxtT = d, mxT = d + (t[0][u] + t[1][u]) * (t[0][v[0]] + t[1][v[0]]);
                while (nxtT < mxT) {
                    if (getColor(u, nxtT) == getColor(v[0], nxtT)) {
                        break;
                    }
                    nxtT++;
                }
                if (nxtT == mxT) continue;
                if (nxtT + v[1] < dist[v[0]]) {
                    dist[v[0]] = nxtT + v[1];
                    pq.push({ dist[v[0]], v[0] });
                    par[v[0]] = u;
                }
            }
        }
        return dist[dest] == INT_MAX ? 0 : dist[dest];
    };

    int ans = dijkstra();
    cout << ans << "\n";
    if (ans) {
        vector<int> path = { dest };
        int b = dest;
        while (b != src) {
            b = par[b];
            path.push_back(b);
        }
        reverse(path.begin(), path.end());
        for (int i = 0; i < (int)path.size(); i++) {
            cout << path[i] << (i == (int)path.size() - 1 ? "\n" : " ");
        }
    }

    return 0;
}
