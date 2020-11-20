// https://codeforces.com/contest/1437/submission/96908358
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int cnt = 2;
int nxt[N][26], link[N], val[N], top[N];
multiset<int> vals[N];
void build() {
    queue<int> que; que.push(1);
    fill(nxt[0], nxt[0] + 26, 1);
    while (!que.empty()) {
        int u = que.front(); que.pop();
        top[u] = val[link[u]] >= 0 ? link[u] : top[link[u]];
        for (int c = 0; c < 26; c++) {
            if (nxt[u][c] == 0) nxt[u][c] = nxt[link[u]][c];
            else {
                link[nxt[u][c]] = nxt[link[u]][c];
                que.push(nxt[u][c]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    memset(val, -1, sizeof val);
    int n, q;
    cin >> n >> q;
    vector<int> ed(n);
    val[1] = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int p = 1;
        for (auto c : s) {
            if (nxt[p][c - 'a'] == 0) nxt[p][c - 'a'] = cnt++;
            p = nxt[p][c - 'a'];
        }
        ed[i] = p;
        vals[p].insert(0);
        val[p] = 0;
    }
    build();
    vector<int> v(n);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int i, x; cin >> i >> x;
            i--;
            int p = ed[i];
            vals[p].erase(vals[p].find(v[i]));
            v[i] = x;
            vals[p].insert(x);
            val[p] = *vals[p].rbegin();
        } else {
            string s; cin >> s;
            int p = 1, ans = -1;
            for (auto c : s) {
                p = nxt[p][c - 'a'];
                for (int q = p; q != 1; q = top[q]) {
                    if (val[q] > ans) ans = val[q];
                }
            }
            cout << ans << "\n";
        }
    }

    return 0;
}
