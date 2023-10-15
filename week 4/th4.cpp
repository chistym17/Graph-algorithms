#include<bits/stdc++.h>
using namespace std;

vector<int> alist[100];
int visited[100];

bool dfs(int node, vector<int>& recursionStack) {
    visited[node] = 1;
    recursionStack[node] = 1;

    for (auto v : alist[node]) {
        if (visited[v] == 0) {
            if (dfs(v, recursionStack))
                return true;
        }
        else if (recursionStack[v] == 1)
            return true;
    }

    recursionStack[node] = 0;
    return false;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        alist[u].push_back(v);
    }

    bool cycleExists = false;
    for (int i = 1; i <= nodes; i++) {
        if (visited[i] == 0) {
            vector<int> recursionStack(nodes + 1, 0);
            if (dfs(i, recursionStack)) {
                cycleExists = true;
                break;
            }
        }
    }

    if (cycleExists)
        cout << "Cycle exists";
    else
        cout << "No cycle";

    return 0;
}
