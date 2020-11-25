#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 5);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<vector<int>> mx(n + 5, vector<int>(15));
    for (int i = 0; i < 15; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 0) {
                mx[j][i] = arr[j];
            } else {
                int j1 = j + (1 << (i));
                if (j1 > n + 1) continue;
                mx[j][i] = max(mx[j][i - 1], mx[j1 - (1 << (i - 1))][i - 1]);
            }
        }
    }
    function<int(int, int)> getMax = [&](int l, int r) -> int {
        int k = floor(log2(r - l + 1));
        return max(mx[l][k], mx[r + 1 - (1 << k)][k]);
    };

    vector<long long> dp(n + 5);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            dp[i] = max(dp[i], dp[i - j] + 1LL * j * getMax(i - j + 1, i));
        }
        // cout << "dp " << i << " " << dp[i] << endl;
    }
    cout << dp[n] << "\n";

    return 0;
}
