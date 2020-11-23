#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t; cin >> t;
    while (t--) {
        function<void(void)> solve = [&]() {
            int n, k, ct[2][27] = {};
            string s[2];
            cin >> n >> k;
            for (int i = 0; i < 2; i++) {
                cin >> s[i];
                for (char c : s[i]) {
                    ct[i][c - 'a']++;
                }
            }

            for (int i = 0; i < 26; i++) {
                if (ct[0][i] < ct[1][i]) {
                    cout << "NO\n";
                    return;
                }
                ct[0][i] -= ct[1][i];
                if (ct[0][i] % k != 0) {
                    cout << "NO\n";
                    return;
                }
                ct[0][i + 1] += ct[0][i];
            }
            if (ct[0][26] != 0) {
                cout << "NO\n";
                return;
            }
            cout << "YES\n";
        }; solve();
    }

    return 0;
}
