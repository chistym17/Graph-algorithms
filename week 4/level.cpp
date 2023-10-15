#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int mat[N][N];
int visited[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int n, m;
int room_count = 0;
int longest_room = 0;

bool is_inside(pair<int, int> cord) {
    int x = cord.first;
    int y = cord.second;
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool is_floor(pair<int, int> cord) {
    int x = cord.first;
    int y = cord.second;
    return (mat[x][y] == 0);
}

void bfs(pair<int, int> src) {
    queue<pair<int, int>> q;
    visited[src.first][src.second] = 1;
    q.push(src);

    int roomLength = 0;
    while (!q.empty()) {
        pair<int, int> h = q.front();
        q.pop();
        int x = h.first;
        int y = h.second;

        roomLength++;
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            pair<int, int> adj_node = {new_x, new_y};
            if (is_inside(adj_node) && is_floor(adj_node) && visited[new_x][new_y] == 0) {
                visited[new_x][new_y] = 1;
                q.push(adj_node);
            }
        }
    }

    longest_room = max(longest_room, roomLength);
}

int main() {
    cin >> n >> m;
    pair<int, int> src, dst;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++) {
            if (input[j] == '#') {
                mat[i][j] = -1;
            } else if (input[j] == '.') {
                mat[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0 && visited[i][j] == 0) {
                room_count++;
                bfs({i, j});
            }
        }
    }

    cout << room_count<<"\n" ;
    cout << longest_room ;

    return 0;
}
