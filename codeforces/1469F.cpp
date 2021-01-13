#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> L(n + 5);
    for (int i = 1; i <= n; i++) cin >> L[i];
    sort(L.begin() + 1, L.begin() + n + 1);
    reverse(L.begin() + 1, L.begin() + n + 1);

    function<bool(long long)> check = [&](long long m) {
        map<array<long long, 2>, int> M = { {{0, 0}, 1} };
        for (int i = 1; i <= n; i++) {
            if ((int)M.size() == 0) break;
            array<long long, 2> tmp = (*M.begin()).first;
            int ct = (*M.begin()).second;
            if (tmp[0] >= m - 1) break;

            if (ct == 1) M.erase(M.begin());
            else M[tmp] = ct - 1;
            if (tmp[0] < tmp[1]) M[{tmp[0] + 1, tmp[1]}]++;

            int a = (L[i] - 1) / 2, b = L[i] / 2;
            M[{tmp[0] + 2, tmp[0] + 1 + a}]++;
            M[{tmp[0] + 2, tmp[0] + 1 + b}]++;
        }
        long long total = 0;
        for (auto p : M) {
            array<long long, 2> tmp = p.first;
            total += max(0LL, 1LL * (min(tmp[1], m) - tmp[0] + 1) * p.second);
        }
        return total >= k;
    };

    long long l = 1, r = 2e10;
    while (l < r) {
        long long m = (l + r) / 2;
        bool res = check(m);
        if (res) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << (check(l) ? l : -1) << "\n";

    return 0;
}
