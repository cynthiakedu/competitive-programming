#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<array<int, 2>>> adj(n + 5);
    for (int i = 0, a, b, t; i < m; i++) {
        cin >> a >> b >> t;
        adj[a].push_back({ b, t });
        adj[b].push_back({ a, t });
    }
    vector<array<int, 2>> tasty(k + 5);
    for (int i = 1; i <= k; i++) {
        cin >> tasty[i][0] >> tasty[i][1];
    }

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<int> dist(n + 5);
    function<void(void)> dijkstra = [&]() {
        while (!pq.empty()) {
            ii x = pq.top(); pq.pop();
            int u = x.second, d = x.first;
            if (d > dist[u]) continue;
            for (auto v : adj[u]) {
                if (dist[u] + v[1] < dist[v[0]]) {
                    dist[v[0]] = dist[u] + v[1];
                    pq.push({ dist[v[0]], v[0] });
                }
            }
        }
    };

    fill(dist.begin(), dist.end(), INT_MAX);
    dist[n] = 0;
    pq.push({ 0, n });
    dijkstra();
    vector<int> dist1(dist.begin(), dist.end());


    fill(dist.begin(), dist.end(), INT_MAX);
    for (int i = 1; i <= k; i++) {
        int x = tasty[i][0], y = tasty[i][1];
        int d2 = dist1[x] - y;
        dist[x] = d2;
        pq.push({ d2, x });
    }
    dijkstra();
    vector<int> dist2(dist.begin(), dist.end());

    for (int i = 1; i < n; i++) {
        bool ok = true;
        if (dist2[i] > dist1[i]) ok = false;
        cout << ok << endl;
    }

    return 0;
}
