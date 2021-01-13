#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n, q;
    cin >> n >> q;
    int b = min(15, n);

    ll xs = 1;
    vector<ll> a(n + 5);
    for (int i = 1; i <= n - b; i++) a[i] = i;
    for (int i = 2; i <= n; i++) a[i] += a[i - 1];

    vector<ll> fact(b + 5); fact[0] = 1;
    for (ll i = 1; i <= b + 1; i++) fact[i] = i * fact[i - 1];
    auto solve = [&](ll idx) {
        vector<ll> ret = { 0 };
        vector<int> S;
        for (int i = n - b + 1; i <= n; i++) S.push_back(i);
        for (int i = 1; i <= b; i++) {
            ll ct = (idx + fact[b - 1] - 1) / fact[b - 1];
            ret.push_back(S[ct - 1]);
            S.erase(S.begin() + (ct - 1));
            idx -= fact[b - 1] * (ct - 1);
        }
        for (int i = 1; i < (int)ret.size(); i++) {
            ret[i] += ret[i - 1];
        }
        return ret;
    };

    for (int i = 0; i < q; i++) {
        int type, l, r, x;
        cin >> type;
        if (type == 1) {
            cin >> l >> r;
            vector<long long> ret = solve(xs);
            ll ans = a[r] - a[l - 1];
            l = max(l, n - b + 1), r = min(r, n);
            if (l <= r) {
                ans += ret[r - (n - b)] - ret[l - (n - b) - 1];
            }
            cout << ans << "\n";
        } else {
            cin >> x;
            xs += x;
        }
    }
    return 0;
}
