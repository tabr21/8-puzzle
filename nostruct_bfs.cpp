/**
 *   8-puzzle using BFS
**/
#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>> start, vector<vector<int>> goal) {
    queue<vector<vector<int>>> que;
    que.emplace(start);
    map<vector<vector<int>>, int> mp;
    mp[start] = 0;
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    while (!que.empty()) {
        vector<vector<int>> v = que.front();
        que.pop();
        int x, y;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (v[i][j] == 0) {
                    x = i;
                    y = j;
                }
            }
        }
        for (int k = 0; k < 4; k++) {
            int new_x = x + dx[k];
            int new_y = y + dy[k];
            if (0 <= new_x && new_x < 3 && 0 <= new_y && new_y < 3) {
                vector<vector<int>> next_v = v;
                swap(next_v[x][y], next_v[new_x][new_y]);
                if (mp.find(next_v) != mp.end()) {
                    continue;
                }
                mp[next_v] = mp[v] + 1;
                que.emplace(next_v);
                if (next_v == goal) {
                    cout << "min_distance: " << mp[next_v] << '\n';
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

int main() {
    vector<vector<int>> start(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> start[i][j];
        }
    }
    vector<vector<int>> goal = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    bfs(start, goal);
    return 0;
}
