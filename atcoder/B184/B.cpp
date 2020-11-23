#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n, x; cin >> n >> x;
    string s; cin >> s;

    for (auto c : s) {
        if (c == '0') x++;
        else if (x) x--;
    }
    cout << x << "\n";

    return 0;
}
