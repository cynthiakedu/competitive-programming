#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int x = abs(r1 - r2), y = abs(c1 - c2);
    int ans = 3;
    if (x + y == 0) {
        ans = 0;
    } else if (x + y <= 3 || x == y) {
        ans = 1;
    } else if (abs(x - y) <= 6 || (x + y) % 2 == 0 || abs(x - y) == 3) {
        ans = 2;
    }
    cout << ans << "\n";

    return 0;
}
