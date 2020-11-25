#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
long long inv(long long a, long long b) {
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
int inv(int a) {
    return inv(a, mod);
}
int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;
    vector<int> tmp(n + 5);

    tmp[0] = 1, tmp[1] = inv(2), tmp[2] = inv(4);
    for (int i = 3; i <= n; i++) {
        tmp[i] = add(1LL * inv(2) * tmp[i - 1] % mod, 1LL * inv(4) * tmp[i - 2] % mod);
    }
    cout << tmp[n] << "\n";
    return 0;
}
