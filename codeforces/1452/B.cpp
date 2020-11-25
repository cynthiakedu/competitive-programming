#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll s = 0, mx = 0, x;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            mx = max(mx, x);
            s += x;
        }
        cout << max((s + n - 2) / (n - 1), 1LL * mx) * (n - 1) - s << "\n";
    }


    return 0;
}
