#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {

    vector<vector<pair<int, int>>> list(n + 1);

    for (auto val : times) {
        int u = val[0], v = val[1], w = val[2];
        list[u].push_back(make_pair(v,w));
    }

    vector<int> dist(n + 1, INT_MAX);

    dist[k] = 0;

    queue<int> q;
    q.push(k);

    while (!q.empty()) {
        int selected_node = q.front();
        q.pop();

        for (auto neighbor : list[selected_node]) {
            int new_dist = dist[selected_node] + neighbor.second;
            if (new_dist < dist[neighbor.first]) {
                dist[neighbor.first] = new_dist;
                q.push(neighbor.first);
            }
        }
    }

    int min_time = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INT_MAX) {
            return -1;
        }
        min_time = max(min_time, dist[i]);
    }

    return min_time;
}

int main() {
    int n = 4;
    int k = 2;
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    cout << networkDelayTime(times, n, k) << endl; // Output: 2
    return 0;
}
