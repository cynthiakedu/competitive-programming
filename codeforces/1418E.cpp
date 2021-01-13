#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int md = 998244353;
ll inv(ll a, ll b) {
    return a > 1 ? b - inv(b % a, a) * b / a : 1;
}
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> d(n + 5), dcm(n + 5);
    for (int i = 1; i <= n; i++) cin >> d[i];
    sort(d.begin() + 1, d.begin() + n + 1);
    for (int i = 1; i <= n; i++) { dcm[i] = (d[i] + dcm[i - 1]) % md; }

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        int x = n + 1 - (int)(lower_bound(d.begin() + 1, d.begin() + n + 1, b) - d.begin());
        int y = n - x;
        if (x < a) {
            cout << 0 << "\n";
            continue;
        }
        int sx = add(dcm[n] - dcm[y], md), sy = dcm[y];
        int ans1 = 1LL * sy * inv(x + 1, md) % md;
        ans1 = 1LL * ans1 * (x - a + 1) % md;
        int ans2 = 1LL * sx * inv(x, md) % md;
        ans2 = 1LL * ans2 * (x - a) % md;
        cout << add(ans1, ans2) << "\n";
    }

    return 0;
}
