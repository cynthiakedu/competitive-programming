#include <bits/stdc++.h>
using namespace std;

const int md = 1e9 + 7;
void add(int& x, int y) {
    x += y;
    if (x >= md) x -= md;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n + 5);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> dp1(n + 5, vector<int>(k + 5));
    for (int j = 1; j <= k + 1; j++) {
        for (int i = 1; i <= n; i++) {
            if (j == 1) {
                dp1[i][j] = 1;
            } else {
                if (i > 1) add(dp1[i][j], dp1[i - 1][j - 1]);
                if (i < n) add(dp1[i][j], dp1[i + 1][j - 1]);
            }
        }
    }

    vector<int> dp2(n + 5);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            int a = j + 1, b = k - j + 1;
            add(dp2[i], 1LL * dp1[i][a] * dp1[i][b] % md);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        add(ans, 1LL * dp2[i] * a[i] % md);
    }

    for (int i = 0; i < q; i++) {
        int idx, x;
        cin >> idx >> x;
        add(ans, 1LL * (x - a[idx] + md) % md * dp2[idx] % md);
        cout << ans << "\n";
        a[idx] = x;
    }
    return 0;
}
