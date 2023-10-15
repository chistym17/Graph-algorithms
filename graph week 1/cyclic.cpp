#include<bits/stdc++.h>

using namespace std;
vector<int>alist[100];
int visited[100];
bool dfs(int node)
{
    visited[node]=1;
    for(auto v:alist[node])
    {
        if(visited[v]==0)
        {
           bool ans= dfs(v);
           if(ans)return true;
        }
        else if(visited[v]==1)
        {
            return true;
        }
    }
    visited[node]=2;
    return false;
}
int main()
{
int nodes,edges;
cin>>nodes>>edges;
for(int i=0;i<edges;i++)
{
    int u,v;
    cin>>u>>v;
    alist[u].push_back(v);
    
}bool ans;
for(int i=1;i<=nodes;i++)
{
    if(visited[i]==0)
    { ans=dfs(i);
          if(ans){cout<<"cycle exists";
           break;
          }


    }
}

    cout<<"No cycle";

    return 0;
}