#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n + 5);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        int idx = 2, ans = 0, ct = 1, ct2 = 0;
        while (idx < n + 1) {
            int j = idx + 1;
            while (j < n + 1 && arr[j] > arr[j - 1]) {
                j++;
            }
            if (ct2 == 0) ans++;
            ct2 += j - idx;
            ct--;
            if (ct == 0) {
                ct = ct2;
                ct2 = 0;
            }
            idx = j;
        }
        cout << ans << "\n";
    }

    return 0;
}
