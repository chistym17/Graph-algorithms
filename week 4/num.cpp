#include <iostream>
#include <limits>

using namespace std;

const int N = 1000;
const int INF = numeric_limits<int>::max();

int main() {
    int mat[N][N];
    int n, m, q;
    cin >> n >> m >> q;

    // Initialize the matrix with infinity
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = INF;
        }
    }

    // Read the edges and weights
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mat[u - 1][v - 1] = min(mat[u - 1][v - 1], w);
        mat[v - 1][u - 1] = min(mat[v - 1][u - 1], w);
    }

    // Set the diagonal elements to 0
    for (int i = 0; i < n; i++) {
        mat[i][i] = 0;
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                mat[u][v] = min(mat[u][v], mat[u][k] + mat[k][v]);
            }
        }
    }

    // Query for shortest paths
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        if (mat[u - 1][v - 1] == INF) {
            cout << "-1\n";
        } else {
            cout << mat[u - 1][v - 1] << "\n";
        }
    }

    return 0;
}
