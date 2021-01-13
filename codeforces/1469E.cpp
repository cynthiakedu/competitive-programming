#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int q; cin >> q;
    while (q--) {
        []() {
            int n, k;
            cin >> n >> k;
            string s;
            cin >> s;

            string s1;
            for (int i = 0; i < n; i++) {
                s1 += s[i] == '0' ? '1' : '0';
            }

            vector<int> freq(n + 5);
            for (int i = 1; i <= n; i++) {
                if (s[i - 1] == '0') freq[i]++;
                freq[i] += freq[i - 1];
            }

            int a = min((int)ceil(log2((n - k + 1) + 1)), k);
            int t = k - a;
            set<string> S;

            for (int i = 0; i < n - k + 1; i++) {
                if (freq[i + t] - freq[i]) continue;
                S.insert(s1.substr(i + t, a));
            }

            int Pow = 1, tmp = 2;
            for (int i = 0; i < 31; i++) {
                if (tmp > 2 * n) break;
                if (a & (1 << i)) Pow = Pow * tmp;
                tmp = tmp * tmp;
            }

            string ans = "";
            for (int i = 0; i < t; i++) ans += '0';
            for (int i = 0; i < Pow; i++) {
                string tmp = "";
                for (int j = a - 1; j >= 0; j--) {
                    tmp += (i & (1 << j)) ? '1' : '0';
                }
                if (S.count(tmp) == 0) {
                    ans += tmp;
                    cout << "YES\n";
                    cout << ans << "\n";
                    return;
                }
            }
            cout << "NO\n";
        }();
    }
    return 0;
}
