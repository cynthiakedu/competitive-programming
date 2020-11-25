//still times out on one test case
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);

    int n;
    cin >> n;
    map<vector<int>, int> v;
    vector<int> tmp(5);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) cin >> tmp[j];
        sort(tmp.begin(), tmp.end());

        for (int k = 1; k < (1 << 5); k++) {
            vector<int> tmp2(6);
            int ct = 0;
            for (int j = 0; j < 5; j++) {
                if (k & (1 << j)) {
                    tmp2[ct++] = tmp[j];
                }
            }
            tmp2[5] = ct;
            ++v[tmp2];
        }
    }

    long long ans = 1LL * n * (n - 1) / 2;
    for (auto tmp : v) {
        int x = tmp.second;
        ans += 1LL * x * (x - 1) / 2 * (tmp.first[5] & 1 ? -1 : 1);
    }
    cout << ans << "\n";

    return 0;
}
