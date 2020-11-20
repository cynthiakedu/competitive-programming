#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n + 5);
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            arr[x]++;
        }
        vector<vector<int>> dp(n + 5, vector<int>(405, INT_MAX));
        vector<vector<int>> mn(n + 5, vector<int>(405, INT_MAX));

        for (int i = n; i >= 1; i--) {
            for (int j = 404; j >= 1; j--) {
                if (j + arr[i] < 405) {
                    int tmp = 0;
                    for (int k = j; k < j + arr[i]; k++) tmp += abs(k - i);
                    if (mn[i + 1][j + arr[i]] < INT_MAX) {
                        dp[i][j] = min(dp[i][j], tmp + mn[i + 1][j + arr[i]]);
                        mn[i][j] = min(mn[i][j + 1], dp[i][j]);
                    }

                }
            }
        }
        cout << mn[1][1] << "\n";
    }

    return 0;
}
