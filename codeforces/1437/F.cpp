#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long add(long long& a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}
long long inv(long long a, long long b) {
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
long long inv(long long a) { return inv(a, MOD); }

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    vector<long long> fact(5005); fact[0] = 1;
    for (long long i = 1; i < 5005; i++) fact[i] = (fact[i - 1] * i) % MOD;

    int n; cin >> n;
    vector<int> arr(n + 5);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr.begin() + 1, arr.begin() + n + 1);
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[n] / 2) {
            cout << 0 << "\n";
            return 0;
        }
    }
    vector<vector<long long>> dp(n + 5, vector<long long>(32, 0));

    for (int i = 0; i <= n - 1; i++) {
        for (int j = 31; j >= 1; j--) {
            if (i == 0) {
                dp[i][j] = 1;
                continue;
            }
            add(dp[i][j], (n - i) * dp[i - 1][j] % MOD);
            //add new barrier
            if (j < 31) {
                int k = i - 1;
                while (k >= 1 && arr[k] > arr[i] / 2) k--;
                long long tmp = inv(fact[n - i - 1]) * fact[n - k - 2] % MOD;
                tmp = tmp * dp[k][j + 1] % MOD;
                add(dp[i][j], tmp);
            }
            // cout << "dp " << i << " " << j << " " << dp[i][j] << "\n";
        }
    }
    cout << dp[n - 1][1] << "\n";


    return 0;
}
