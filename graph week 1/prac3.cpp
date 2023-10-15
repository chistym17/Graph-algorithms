#include<bits/stdc++.h>
using namespace std;

int main() {

    // n = number of nodes
    // m = number of edges
    int n, m;
     n=4;m=4;

    // TODO: Declare your favorite data structures here.
    vector<vector<int>>list;




    for(int i = 0 ; i < m ; i++) { // loop over the number of edges
        int u, v;
        cin >> u >> v; // there exists an edge between node u and v

        // TODO: Do stuffs with u and v
        list.push_back({u,v});
    }

    // TODO: Print your representation like shown in module - 2
    for(int i=0;i<m;i++)
    {
        cout<<list[i][0]<<" "<<list[i][1];
        cout<<"\n";
    }
    


    return 0;
}
