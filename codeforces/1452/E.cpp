#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<array<int, 2>> v(m + 5), v2(m + 5);
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        v[i] = { x, y };
        v2[i] = { (x + y) / 2, i };
    }
    sort(v2.begin() + 1, v2.begin() + m + 1);

    vector<vector<int>> pre(2, vector<int>(m + 5, 0));
    for (int i = 0; i < 2; i++) {
        vector<int> tmp(n + 5, 0);
        for (int j = 1; j <= m; j++) {
            for (int s = v[v2[j][1]][0]; s <= v[v2[j][1]][1];s++) tmp[s]++;
            int ct = 0;
            for (int s = 1; s <= k; s++) ct += tmp[s];
            pre[i][j] = max(pre[i][j], ct);
            for (int s = 2;s <= n - k + 1;s++) {
                ct += tmp[s + k - 1] - tmp[s - 1];
                pre[i][j] = max(pre[i][j], ct);
            }
        }
        reverse(v2.begin() + 1, v2.begin() + m + 1);
    }

    int ans = 0;
    for (int i = 0; i <= m; i++) {
        ans = max(ans, pre[0][i] + pre[1][m - i]);
    }
    cout << ans << "\n";


    return 0;
}
