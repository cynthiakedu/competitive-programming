#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t; cin >> t;
    while (t--) {
        long long d, k, d2; cin >> d >> k;
        d2 = d * d;
        long long x = 0, y = 0, p;
        for (int i = 0;i < 1e5;i++) {
            x += k;
            if (x * x + y * y > d * d) {
                p = 1;
                break;
            }
            y += k;
            if (x * x + y * y > d * d) {
                p = 0;
                break;
            }
        }
        if (p == 0) {
            cout << "Ashish\n";
        } else {
            cout << "Utkarsh\n";
        }
    }

    return 0;
}
