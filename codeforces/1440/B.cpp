#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t;  cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n * k + 5);
        for (int i = 1; i <= n * k; i++) cin >> arr[i];
        int b = (n + 1) / 2 - 1;
        int amt = k * b;
        long long sum = 0;
        for (int i = 1; i <= k;i++) {
            sum += arr[amt + (i - 1) * (n - b) + 1];
        }
        cout << sum << "\n";
    }

    return 0;
}
