#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    const int mxN = 1e4 + 5;
    vector<int> primes, vis(mxN);
    for (int i = 2; i < mxN; i++) {
        if (vis[i]) continue;
        primes.push_back(i);
        for (int j = i; j < mxN; j += i) {
            vis[j] = true;
        }
    }

    int n, n1;
    cin >> n;
    n1 = n;
    for (int p : primes) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            n1 = n1 / p * (p - 1);
        }
    }
    if (n > 1) n1 = n1 / n * (n - 1);
    cout << n1 << "\n";
    return 0;
}
