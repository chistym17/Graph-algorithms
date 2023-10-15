#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 1000;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int n, m;
char mat[N][N];
int visited[N][N];
int level[N][N];

bool isInside(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool isSafe(char cell) {
    return (cell == '.' || cell == 'A');
}

bool bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = 1;
    level[startX][startY] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (isSafe(mat[x][y]) && (x == 0 || x == n - 1 || y == 0 || y == m - 1)) {
            return true; // Reached a safe boundary cell
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if (isInside(newX, newY) && isSafe(mat[newX][newY]) && !visited[newX][newY]) {
                q.push({newX, newY});
                visited[newX][newY] = 1;
                level[newX][newY] = level[x][y] + 1;
            }
        }
    }

    return false; // Goal not reachable
}

int main() {
    cin >> n >> m;

    int startX, startY;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'A') {
                startX = i;
                startY = j;
            }
        }
    }

    if (bfs(startX, startY)) {
        cout << "YES\n";

        vector<char> path;
        int x = startX, y = startY;

        while (x != 0 || x != n - 1 || y != 0 || y != m - 1) {
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                
                if (isInside(newX, newY) && level[newX][newY] == level[x][y] - 1) {
                    if (i == 0) path.push_back('L');
                    else if (i == 1) path.push_back('R');
                    else if (i == 2) path.push_back('U');
                    else if (i == 3) path.push_back('D');
                    x = newX;
                    y = newY;
                    break;
                }
            }
        }

        reverse(path.begin(), path.end());

        cout << path.size() << '\n';
        for (char dir : path) {
            cout << dir;
        }
        cout << '\n';
    } else {
        cout << "NO\n";
    }

    return 0;
}
