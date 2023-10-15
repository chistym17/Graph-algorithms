#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;
vector<int> adjList[N];
int visited[N]={0};

void dfs(int node) {
    visited[node] = 1;
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
   long int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    dfs(1);

    if (visited[n]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
