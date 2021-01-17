/**
 *   8-puzzle using BFS
**/
#include <bits/stdc++.h>

using namespace std;

struct node {
    vector<vector<int>> puzzle;
    int x;
    int y;

    bool operator<(const node &other) const {
        return puzzle < other.puzzle;
    }
};

void bfs(node start, node goal) {
    queue<node> que;
    que.emplace(start);
    map<node, int> mp;
    mp[start] = 0;
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    while (!que.empty()) {
        node v = que.front();
        que.pop();
        for (int k = 0; k < 4; k++) {
            node next_v = v;
            next_v.x = v.x + dx[k];
            next_v.y = v.y + dy[k];
            if (0 <= next_v.x && next_v.x < 3 && 0 <= next_v.y && next_v.y < 3) {
                swap(next_v.puzzle[v.x][v.y], next_v.puzzle[next_v.x][next_v.y]);
                if (mp.find(next_v) != mp.end()) {
                    continue;
                }
                mp[next_v] = mp[v] + 1;
                que.emplace(next_v);
                if (next_v.puzzle == goal.puzzle) {
                    cout << "min_distance: " << mp[next_v] << '\n';
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

int main() {
    node start;
    start.puzzle = vector<vector<int>>(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> start.puzzle[i][j];
        }
    }
    node goal;
    goal.puzzle = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    bfs(start, goal);
    return 0;
}