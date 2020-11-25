#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MXN = 100005;

int solve(string x) {
    int ct = 0, ret = 0;
    for (char c : x) {
        if (c == 'l') ct++;
        else if (ct > 0) {
            ret++, ct--;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s; cin >> s;
        int ans = 0;
        string a, b;
        for (char c : s) {
            if (c == '(' || c == ')') {
                a += (c == '(' ? 'l' : 'r');
            } else {
                b += (c == '[' ? 'l' : 'r');
            }
        }
        cout << solve(a) + solve(b) << "\n";
    }

    return 0;
}
