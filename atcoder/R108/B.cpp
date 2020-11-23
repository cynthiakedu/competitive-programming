#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n;
    string s, t;
    cin >> n >> s;

    for (char c : s) {
        t += c;
        if (t.size() >= 3 && t.substr(t.size() - 3) == "fox") {
            t.resize(t.size() - 3);
        }
    }
    cout << t.size() << "\n";

    return 0;
}
