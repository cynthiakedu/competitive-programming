#include <bits/stdc++.h>
using namespace std;

void bad() {
    cout << -1 << "\n";
    exit(0);
}

int solve(vector<int> v) {
    int n = (int)v.size();
    for (int i = 0; i < n; i++) v[i] -= i;
    if (v[n - 1] < v[0]) bad();

    vector<int> v2(n + 5, INT_MAX);
    int ret = 0;
    for (int i = 1; i < n - 1; i++) {
        int x = v[i];
        if (x < v[0] || x > v[n - 1]) continue;
        int pos = (int)(upper_bound(v2.begin(), v2.end(), x) - v2.begin());
        ret = max(ret, pos + 1);
        v2[pos] = x;
    }
    return n - 2 - ret;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> arr(n + 5), b(k + 5);

    for (int i = 1; i <= n; i++) cin >> arr[i];
    arr[0] = INT_MIN, arr[n + 1] = INT_MAX;
    for (int i = 1; i <= k; i++) cin >> b[i];
    b[0] = 0, b[k + 1] = n + 1;

    for (int i = 0; i <= k; i++) {
        vector<int> v;
        for (int j = b[i]; j <= b[i + 1]; j++) {
            v.push_back(arr[j]);
        }
        ans += solve(v);
    }
    cout << ans << "\n";

    return 0;
}
