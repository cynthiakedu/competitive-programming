#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int a, b, c; cin >> a >> b >> c;
    float dp[105][105][105] = {};
    for (int i = 100; i >= 0; i--) {
        for (int j = 100; j >= 0; j--) {
            for (int k = 100; k >= 0; k--) {
                // cout << "i j k " << i << " " << j << " " << k << endl;
                if (i == 100 || j == 100 || k == 100) {
                    dp[i][j][k] = 0;
                    continue;
                }
                int s = i + j + k;
                float& ret = dp[i][j][k];
                ret = 1;
                ret += 1.0 * i / s * dp[i + 1][j][k];
                ret += 1.0 * j / s * dp[i][j + 1][k];
                ret += 1.0 * k / s * dp[i][j][k + 1];
            }
        }
    }
    cout << setprecision(16) << dp[a][b][c] << "\n";
    return 0;
}
