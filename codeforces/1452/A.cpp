#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MXN = 100005;


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        x = abs(x), y = abs(y);
        if (y > x) swap(x, y);
        cout << x + y + max(0, x - 1 - y) << "\n";
    }

    return 0;
}
