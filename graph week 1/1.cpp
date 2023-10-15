#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int mat[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> list(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                list[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i << "->";
        for (int j = 0; j < list[i].size(); j++) {
            cout << list[i][j] << " ";
            
        }
        cout<<"\n";
    }

    return 0;
}
