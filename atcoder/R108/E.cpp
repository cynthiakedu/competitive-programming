#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}
long long inv(long long a, long long b) {
    return a > 1 ? b - inv(b % a, a) * b / a : 1;
}
int inv(int a) {
    if (a == 0) return 0;
    return inv(a, mod);
}

struct FenwickTree {
    vector<int> v;
    FenwickTree(int n) {
        v.resize(n + 5, 0);
    }
    void modify(int k, int val) {
        if (k == 0) return;
        for (; k < (int)v.size(); k += k & (-k)) {
            v[k] = add(v[k], val);
        }
    }
    int query(int b) {
        int ret = 0;
        for (; b; b -= b & (-b)) {
            ret = add(ret, v[b]);
        }
        return ret;
    }
    int query(int a, int b) {
        if (b < a) return 0;
        return (query(b) - query(a - 1) + mod) % mod;
    }
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n; cin >> n;
    vector<int> arr(n + 5);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    arr[n + 1] = n + 1;

    vector<vector<int>> dp(n + 5, vector<int>(n + 5));
    vector<FenwickTree> l(n + 5, FenwickTree(n + 5));
    vector<FenwickTree> r(n + 5, FenwickTree(n + 5));


    for (int i = n; i >= 0; i--) {
        FenwickTree ct(n + 5);
        for (int j = i + 1; j <= n + 1; j++) {
            int x = arr[i], y = arr[j];
            int tmpCt = ct.query(x + 1, y - 1);
            if (x >= y) continue;

            if (tmpCt) {
                dp[i][j] = add(dp[i][j], l[i].query(x + 1, y - 1));
                dp[i][j] = add(dp[i][j], r[j].query(x + 1, y - 1));
                dp[i][j] = add(dp[i][j], tmpCt);
                dp[i][j] = 1LL * dp[i][j] * inv(tmpCt) % mod;
            }

            l[i].modify(arr[j], dp[i][j]);
            r[j].modify(arr[i], dp[i][j]);
            ct.modify(arr[j], 1);
        }
    }
    cout << dp[0][n + 1] << "\n";

    return 0;
}
