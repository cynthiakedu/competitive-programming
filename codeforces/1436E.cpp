#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int T = (1 << 17);
    vector<int> tree;
    SegTree() {
        tree.resize(2 * T + 5);
    }

    int mn(int a, int b) {
        a += T; b += T;
        int ret = INT_MAX;
        while (a <= b) {
            if (a % 2 == 1) ret = min(ret, tree[a++]);
            if (b % 2 == 0) ret = min(ret, tree[b--]);
            a /= 2, b /= 2;
        }
        return ret;
    }

    void modify(int k, int x) {
        k += T;
        tree[k] = x;
        for (k /= 2; k >= 1; k /= 2) {
            tree[k] = min(tree[2 * k], tree[2 * k + 1]);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n; cin >> n;
    vector<int> arr(n + 5);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<bool> isMex(n + 5, false);
    SegTree segTree;

    auto check = [&](int i) {
        int prev = segTree.mn(arr[i], arr[i]);
        if (arr[i] == 1) {
            if (i - prev > 1) isMex[1] = true;
        } else {
            int lst = segTree.mn(1, arr[i] - 1);
            if (lst > prev) isMex[arr[i]] = true;
        }
    };

    for (int i = 1; i <= n; i++) {
        check(i);
        segTree.modify(arr[i], i);
    }
    for (int i = 1; i <= n + 1; i++) {
        arr[n + 1] = i;
        check(n + 1);
    }

    for (int i = 1; i <= n + 2; i++) {
        if (!isMex[i]) {
            cout << i << "\n";
            return 0;
        }
    }

    return 0;
}
