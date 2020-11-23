#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int h, w; cin >> h >> w;
    vector<vector<char>> arr(h + 5, vector<char>(w + 5));
    vector<vector<int>> dis(h + 5, vector<int>(w + 5, -1));
    vector<vector<array<int, 2>>> same(26);
    array<int, 2> s, g;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') s = { i, j };
            if (arr[i][j] == 'G') g = { i, j };
            int x = arr[i][j] - 'a';
            if (0 <= x && x < 26) same[x].push_back({ i, j });
        }
    }

    queue<array<int, 2>> que;
    que.push(s), dis[s[0]][s[1]] = 0;
    while (!que.empty()) {
        array<int, 2> u = que.front(); que.pop();
        int x = u[0], y = u[1];
        char c = arr[x][y];

        if (c == 'G') break;

        if (c != '.' && c != '#' && c != 'S') {
            for (auto v : same[c - 'a']) {
                if (dis[v[0]][v[1]] == -1) {
                    dis[v[0]][v[1]] = dis[x][y] + 1;
                    que.push({ v[0], v[1] });
                }
            }
            same[c - 'a'].clear();
        }

        vector<int> dx = { -1, 0, 1, 0 };
        vector<int> dy = { 0, -1, 0, 1 };
        for (int i = 0; i < 4; i++) {
            int x1 = x + dx[i], y1 = y + dy[i];
            if (x1 < 0 || x1 >= h) continue;
            if (y1 < 0 || y1 >= w) continue;
            if (arr[x1][y1] == '#') continue;
            if (dis[x1][y1] != -1) continue;
            dis[x1][y1] = dis[x][y] + 1;
            que.push({ x1, y1 });
        }
    }
    cout << dis[g[0]][g[1]] << "\n";


    return 0;
}
