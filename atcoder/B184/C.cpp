#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int x = abs(r1 - r2), y = abs(c1 - c2);
    if (x == 0 && y == 0) {
        cout << "0\n";
    } else if (x + y <= 3 || x == y) {
        cout << "1\n";
    } else if ((x + y) % 2 == 0) {
        cout << "2\n";
    } else {
        if (y < x) swap(x, y);
        int ans = ((x > 0 ? 1 : 0) + (y - x <= 3 ? (y - x == 0 ? 0 : 1) : ((y - x) % 2 ? 3 : 2)));
        ans = min(ans, 3);
        cout << ans << "\n";
    }

    return 0;
}
