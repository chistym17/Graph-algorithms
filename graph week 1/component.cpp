#include<bits/stdc++.h>
using namespace std;

int countcomp(vector<vector<int>>& adjList, vector<bool>& visited) {
    int comp = 0;
    int n = adjList.size();

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            comp++;
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int adj : adjList[node]) {
                    if (!visited[adj]) {
                        visited[adj] = true;
                        q.push(adj);
                    }
                }
            }
        }
    }

    return comp;
}

int main() {
    int nodes, edges;
    cin>>nodes>>edges;

    vector<vector<int>> adjList(nodes);
    vector<bool> visited(nodes, false);

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int ans = countcomp(adjList, visited);

    cout << ans;

    return 0;
}
