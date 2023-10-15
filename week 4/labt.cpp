#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int INF = 1e9;

int nodes, edges;
vector<pair<int, int>> adjlist[N];
int d[N];
int parent[N];

void dijkstra(int src) {
    for (int i = 1; i <= nodes; i++) {
        d[i] = INF;
        parent[i] = -1;
    }

    d[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dist > d[u]) {
            continue;
        }

        for (auto adj : adjlist[u]) {
            int v = adj.first;
            int weight = adj.second;

            if (d[u] + weight < d[v]) {
                d[v] = d[u] + weight;
                parent[v] = u;
                pq.push({d[v], v});
            }
        }
    }
}

int main() {
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjlist[u].push_back({v, w});
        adjlist[v].push_back({u, w});
    }

    dijkstra(1);

    if (d[nodes] == INF) {
        cout << -1 << endl;
    } else {
        vector<int> path;
        int curr = nodes;
        while (curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        
    }

    return 0;
}
