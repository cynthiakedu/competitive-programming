#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        for (int i = 0; i < q; i++) {
            function<void(void)> solve = [&]() {
                int l, r; cin >> l >> r;
                l--, r--;

                for (int i = 0; i < l; i++) {
                    if (s[i] == s[l]) {
                        cout << "YES\n";
                        return;
                    }
                }
                for (int i = r + 1; i < n; i++) {
                    if (s[i] == s[r]) {
                        cout << "YES\n";
                        return;
                    }
                }
                cout << "NO\n";
            };
            solve();
        }
    }

    return 0;
}
