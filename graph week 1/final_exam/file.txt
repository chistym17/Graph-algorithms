#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
const int M = 1e3;

int n, m;
int grid[N][M];
bool visited[N][M];

bool is_valid(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int dfs(int x, int y) {
    if (!is_valid(x, y) || grid[x][y] == 0 || visited[x][y]) {
        return 0;
    }

    visited[x][y] = true;
    int ans = grid[x][y];

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; ++i) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        ans += dfs(new_x, new_y);
    }

    return ans;
}

int largest_volume() {
    int max_volume = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] > 0 && !visited[i][j]) {
                max_volume = max(max_volume, dfs(i, j));
            }
        }
    }

    return max_volume;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = largest_volume();
    cout << result;

    return 0;
}
