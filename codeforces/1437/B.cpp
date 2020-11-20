#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, ans = INT_MAX;
        string s;
        cin >> n >> s;

        for (int i = 0; i < 2; i++) {
            int idx = 0, ct = 0;
            while (idx < n) {
                if ((s[idx] - '0' + idx) % 2 == i) {
                    idx++;
                } else {
                    int j = idx;
                    while (j < n && (s[j] - '0' + j) % 2 != i) {
                        j++;
                    }
                    ct++;
                    idx = j;
                }
            }
            ans = min(ans, ct);
        }
        cout << ans << "\n";
    }

    return 0;
}
