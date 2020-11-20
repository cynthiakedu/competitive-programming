#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t, l, r; cin >> t;
    while (t--) {
        cin >> l >> r;
        cout << (l > r - 1 ? "YES" : "NO") << "\n";
    }

    return 0;
}
