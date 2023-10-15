#include<bits/stdc++.h>
using namespace std;

const int N = 100;
char mat[N][N];
bool visited[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int n, m;
pair<int, int> src;

bool isValidMove(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && mat[x][y] != '#')
        return true;
    else
        return false;
}

string findPath() {
    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = true;
    cout<<"herr 1";

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;
        cout<<"here2";

        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            string path = "";
            while (curr != src) {
                int prev_x = curr.first;
                int prev_y = curr.second;
                if (prev_x < x)
                    path += 'D';
                else if (prev_x > x)
                    path += 'U';
                else if (prev_y < y)
                    path += 'R';
                else
                    path += 'L';
                curr = {prev_x, prev_y};
            }
            reverse(path.begin(), path.end());
            return path;
        }
        cout<<"here4";

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (isValidMove(new_x, new_y)) {
                visited[new_x][new_y] = true;
                q.push({new_x, new_y});
            }
        }
    }
    cout<<"here3";

    return ""; // Return empty string if no valid path is found
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

    string path = findPath();
    if (!path.empty()) {
        cout << "YES" << endl;
        cout << path.length() << endl;
        cout << path << endl;
    } else {
        cout << "NO" << endl;
        cout << 0 << endl;
    }

    return 0;
}
