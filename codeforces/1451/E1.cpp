#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n; cin >> n;
    vector<int> ans(n + 5, 0);

    int x = 0, y = 1;
    while (y != n) {
        x++, y *= 2;
    }
    int a[5];
    cout << "XOR " << 1 << " " << 2 << endl; cin >> a[0]; //
    cout << "AND " << 1 << " " << 2 << endl; cin >> a[1];
    cout << "XOR " << 2 << " " << 3 << endl; cin >> a[2]; //
    cout << "AND " << 2 << " " << 3 << endl; cin >> a[3];
    cout << "AND " << 1 << " " << 3 << endl; cin >> a[4];

    for (int i = x - 1; i >= 0; i--) {
        // cout << "START " << i << endl;
        int b[5], tmp[3];
        for (int j = 0; j < 5; j++) b[j] = ((a[j] & (1 << i)) >> i) & 1;

        for (int d = 0; d < 2; d++) {
            tmp[0] = d;
            tmp[1] = d ^ b[0];
            tmp[2] = tmp[1] ^ b[2];
            bool ok = true;
            if ((tmp[0] & tmp[1]) != b[1]) ok = false;
            if ((tmp[1] & tmp[2]) != b[3]) ok = false;
            if ((tmp[0] & tmp[2]) != b[4]) ok = false;
            if (ok) break;
        }
        for (int j = 0; j < 3; j++) {
            // cout << "tmp " << j << " " << tmp[j] << "\n";
            ans[j] += (1 << i) * tmp[j];
        }
    }

    for (int i = 3; i < n; i++) {
        int tmp;
        cout << "XOR " << 1 << " " << i + 1 << endl; cin >> tmp;
        ans[i] = tmp ^ ans[0];
    }

    cout << "! ";
    for (int i = 0; i < n - 1; i++) cout << ans[i] << " ";
    cout << ans[n - 1] << endl;

    return 0;
}
