#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int MXN = 105;
int N, M, arr[MXN][MXN];
vector<vector<int>> ans;

void process(vector<pair<int, int>> v2) {
    vector<int> v;
    for (int i = 0; i < 3; i++) {
        v.push_back(v2[i].first);
        v.push_back(v2[i].second);
    }
    ans.push_back(v);
    for (int i = 0; i < 6; i += 2) {
        arr[v[i]][v[i + 1]] = 1 - arr[v[i]][v[i + 1]];
    }
}

void solve(vector<pair<int, int>> v[2]) {
    if (v[1].size() == 0) {
        return;
    } else if (v[1].size() == 1) {
        vector<pair<int, int>> v2[2];
        v2[0] = { v[0][0], v[1][0] };
        v2[1] = { v[0][1], v[0][2] };
        process({ v[1][0], v[0][1], v[0][2] });
        solve(v2);
    } else if (v[1].size() == 2) {
        vector<pair<int, int>> v2[2];
        v2[0] = { v[1][0] };
        v2[1] = { v[0][0], v[0][1], v[1][1] };
        process({ v[1][0], v[0][0], v[0][1] });
        solve(v2);
    } else {
        process({ v[1][0], v[1][1], v[1][2] });
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        ans.clear();
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                char c;
                cin >> c;
                arr[i][j] = c - '0';
            }
        }

        //process first N-1 rows
        for (int i = 1; i < N; i++) {
            int idx = 1;
            while (idx <= M) {
                if (!arr[i][idx]) {
                    idx++;
                    continue;
                }
                if (idx < M && arr[i][idx + 1]) {
                    process({ {i, idx}, {i, idx + 1}, {i + 1, idx} });
                    idx += 2;
                } else {
                    process({ {i, idx},{ i + 1, idx}, {i + 1, idx == M ? idx - 1 : idx + 1 } });
                    idx += 1;
                }
            }
        }

        //process last row
        for (int j = 1; j < M - 1; j++) {
            if (arr[N][j] && !arr[N - 1][j]) {
                process({ {N, j}, { N - 1, j + 1}, {N, j + 1} });
            } else if (arr[N][j]) {
                process({ {N, j}, {N - 1, j}, {N, j + 1} });
            } else if (arr[N - 1][j]) {
                process({ { N - 1, j}, {N - 1, j + 1}, {N, j + 1 } });
            }
        }
        vector<pair<int, int>> tmp[2];
        for (int a = N - 1; a <= N; a++) {
            for (int b = M - 1; b <= M; b++) {
                tmp[arr[a][b]].push_back({ a, b });
            }
        }
        solve(tmp);
        cout << ans.size() << "\n";
        for (vector<int> v : ans) {
            for (int i = 0; i < 6; i++) {
                cout << v[i] << (i == 5 ? "\n" : " ");
            }
        }
    }

    return 0;
}
