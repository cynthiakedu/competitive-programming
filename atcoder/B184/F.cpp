#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n; long long t;
    cin >> n >> t;
    vector<int> arr(n + 5);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> v[2];
    vector<long long> p[2];
    int id;
    function<void(int, long long)> solve = [&](int idx, long long sum) {
        if (sum > t) return;

        if (idx == v[id].size()) {
            p[id].push_back(sum);
            return;
        }
        solve(idx + 1, sum);
        solve(idx + 1, sum + v[id][idx]);
    };

    for (int i = 1; i <= n / 2; i++) v[0].push_back(arr[i]);
    for (int i = n / 2 + 1; i <= n; i++) v[1].push_back(arr[i]);
    for (id = 0; id < 2; id++) {
        solve(0, 0);
        sort(p[id].begin(), p[id].end());
    }

    long long ans = 0;
    for (long long x : p[0]) {
        int pos = (int)(lower_bound(p[1].begin(), p[1].end(), t + 1 - x) - p[1].begin());
        if (pos == 0) continue;
        if (p[1][pos - 1] + x > t) continue;
        ans = max(ans, x + p[1][pos - 1]);
    }
    cout << ans << "\n";

    return 0;
}
