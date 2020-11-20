#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, c0, c1, h;
        string s;
        cin >> n >> c0 >> c1 >> h >> s;

        int ct[2] = {}, ans = 0;

        for (int i = 0; i < n; i++) ct[s[i] - '0']++;
        ans = c0 * ct[0] + c1 * ct[1];

        if (c0 + h < c1) {
            ans = c0 * n + h * ct[1];
        } else if (c1 + h < c0) {
            ans = c1 * n + h * ct[0];
        }
        cout << ans << "\n";
    }

    return 0;
}
