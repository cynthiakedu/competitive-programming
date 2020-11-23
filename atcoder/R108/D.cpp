#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int powmod(int a, int b) {
    int ret = 1;
    for (; b; a = 1LL * a * a % mod, b >>= 1) {
        if (b & 1) ret = 1LL * ret * a % mod;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n; cin >> n;
    char aa, ab, ba, bb;
    cin >> aa >> ab >> ba >> bb;

    vector<int> fib(n + 5);
    fib[1] = 1;
    for (int i = 2; i <= n; i++)  fib[i] = (fib[i - 1] + fib[i - 2]) % mod;

    int ans;
    if (n == 2) {
        ans = 1;
    } else if (ab == 'A') {
        if (aa == 'A') ans = 1;
        else if (ba == 'B') ans = powmod(2, n - 3);
        else ans = fib[n - 1];
    } else {
        if (bb == 'B') ans = 1;
        else if (ba == 'A') ans = powmod(2, n - 3);
        else ans = fib[n - 1];
    }
    cout << ans << "\n";
    return 0;
}
