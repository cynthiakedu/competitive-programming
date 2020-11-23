#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    long long s, p;
    cin >> s >> p;
    for (long long p1 = 1; p1 * p1 <= p; p1++) {
        if (p % p1 == 0 && s == p1 + p / p1) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";

    return 0;
}
