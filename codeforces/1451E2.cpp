#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n; cin >> n;

    vector<int> q1(n + 5, 0), q2(n + 5, 0);
    for (int i = 2; i <= n; i++) {
        cout << "XOR " << 1 << " " << i << endl;
        int x; cin >> x;
        q1[i] = x;
    }
    int a = -1, b = -1;
    for (int i = 1; i <= n; i++) {
        int x = q1[i];
        if (q2[x]) {
            a = q2[x], b = i;
        } else {
            q2[x] = i;
        }
    }
    int ans1;
    if (a != -1) {
        cout << "AND " << a << " " << b << endl;
        int x; cin >> x;
        ans1 = x ^ q1[a];
    } else {
        cout << "AND " << q2[0] << " " << q2[1] << endl;
        int x; cin >> x;
        cout << "AND " << q2[0] << " " << q2[2] << endl;
        int y; cin >> y;
        ans1 = (x - x % 2) + y % 2;
    }
    cout << "! " << ans1;
    for (int i = 2; i <= n; i++) {
        cout << " " << (ans1 ^ q1[i]);
    }
    cout << endl;
    return 0;
}
