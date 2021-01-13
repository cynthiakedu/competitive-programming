#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    function<void(void)> bad = []() {
        cout << 0 << "\n";
        exit(0);
    };

    int n, k, rt;
    cin >> n >> k;
    vector<int> p(n + 5), xy(n + 5), ans;
    vector<set<int>> adj(n + 5);
    vector<int> ctr(n + 5), isY(n + 5), l(n + 5);

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] == 0) rt = i;
    }
    for (int i = 1, x, y; i <= k; i++) {
        cin >> x >> y;
        xy[x] = y, isY[y] = 1;
    }
    if (isY[rt]) bad();

    //process chains
    for (int i = 1; i <= n; i++) {
        int x = i;
        if (isY[i]) continue;
        l[i] = i;
        while (xy[x]) {
            //cycle with chain
            if (ctr[xy[x]] || xy[x] == i) bad();

            ctr[xy[x]] = ctr[x] + 1;
            x = xy[x];
            l[x] = i;
        }
    }
    //pure cycles won't be seen by above loop
    for (int i = 1; i <= n; i++) {
        if (isY[i] && !ctr[i]) bad();
    }

    //get adj
    vector<int> deg(n + 5);
    for (int i = 1; i <= n; i++) {
        if (!p[i]) continue;
        int a = p[i];
        int la = l[a], li = l[i];
        if (la == li && ctr[a] > ctr[i]) bad();
        if (la != li) {
            if (!adj[la].count(li)) {
                adj[la].insert(li);
                deg[li]++;
            }
        }
    }

    //bfs
    queue<int> q; q.push(rt);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.push_back(u);
        for (int x : adj[u]) {
            deg[x]--;
            if (!deg[x])q.push(x);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i]) bad();
    }

    vector<int> ans2;
    for (int x : ans) {
        ans2.push_back(x);
        int x1 = x;
        while (xy[x1]) {
            x1 = xy[x1];
            ans2.push_back(x1);
        }
    }
    for (int i = 0; i < (int)ans2.size(); i++) {
        cout << ans2[i] << (i == (int)ans2.size() - 1 ? "\n" : " ");
    }

    return 0;
}
