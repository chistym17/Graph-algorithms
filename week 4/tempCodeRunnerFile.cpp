#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
char mat[N][N];
bool visited[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int n, m;
pair<int, int> src;

bool isValidMove(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && mat[x][y] == '.')
    return true;
    else
    return false;
}

bool bfs() {
    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = true;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (isValidMove(new_x, new_y)) {
                visited[new_x][new_y] = true;
                q.push({new_x, new_y});
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'A')
                src = {i, j};
        }
    }

    if(bfs)cout<<"yes";
    else
    cout<<"no";

    return 0;
}
