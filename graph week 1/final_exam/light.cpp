#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited, int& count) {
    visited[node] = true;
    count++;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, count);
        }
    }
}

int find_max_members(const vector<vector<int>>& graph, int n) {
    int max_members = 0;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            int count = 0;
            dfs(i, graph, visited, count);
            max_members = max(max_members, count);
        }
    }
    return max_members;
}

int main() {
    int T;
    cin >> T;
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        int n;
        cin >> n;
        vector<vector<int>> graph(20001);
        for (int i = 0; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int max_members = find_max_members(graph, 20000);
        cout << "Case " << caseNum << ": " << max_members << endl;
    }
    return 0;
}
