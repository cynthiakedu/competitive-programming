#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

array<ll, 2> egcd(ll a, ll b) {
    ll a0 = a, b0 = b;
    ll x0 = 0, y0 = 1, u = 1, v = 0;
    while (a != 0) {
        ll q = b / a, r = b % a;
        ll m = x0 - u * q, n = y0 - v * q;
        b = a, a = r;
        x0 = u, y0 = v;
        u = m, v = n;
    }
    if (x0 <= 0) {
        int tmp = (abs(x0) + (b0 - 1)) / b0 + 1;
        x0 += tmp * b0;
        y0 -= tmp * a0;
    }
    if ((y0 & 1) == 1) {
        y0 -= a0;
        x0 += b0;
    }
    return { x0, y0 };
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    ll x;
    cin >> x;

    vector<pair<string, array<ll, 2>>> ans;
    auto op_add = [&](ll a, ll b) {ans.push_back({ " + ", {a, b} });};
    auto op_xor = [&](ll a, ll b) {ans.push_back({ " ^ ", {a, b} });};

    auto mult = [&](ll a, ll b) {
        ll curr = 0;
        const ll bd = 2e18;
        for (int i = 0; i <= 62; i++) {
            if (b >> i & 1) {
                if (curr) op_add(curr, a);
                curr += a;
            }
            op_add(a, a);
            a *= 2;
            if (a > bd) break;
        }
    };

    ll lp = (1 << (31 - __builtin_clz(x)));
    mult(x, lp);
    op_xor(lp * x, x);
    ll y = (lp * x) ^ x;

    auto p = egcd(x, y);
    mult(x, p[0]);
    mult(y, -p[1]);
    op_xor(p[0] * x, (-p[1]) * y);

    cout << ans.size() << "\n";
    for (auto tmp : ans) {
        cout << tmp.second[0] << tmp.first << tmp.second[1] << "\n";
    }
    return 0;
}
