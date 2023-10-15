#include<bits/stdc++.h>

using namespace std;
const int n=1000;
vector<int>adjlist[n];
int visited[n];
int color[n];

bool dfs(int node)
{
visited[node]=1;
for(auto v:adjlist[node])
{   
    if(visited[v]==0)
    {
        if(color[node]==1)color[v]=2;
        else color[v]=1;
        bool is_valid=dfs(v);
        if(!is_valid)
        {
            return false;
        }
        
    }
    else{
        if(color[node]==color[v])
        return false;


    }
}

return true;


}
int main()
{
int nodes,edges;
cin>>nodes>>edges;
for(int i=0;i<edges;i++)
{
    int u,v;
    cin>>u>>v;
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
    
}
bool is_biphartite=true;
for(int i=1;i<=nodes;i++)
{   
    if(visited[i]==0)
    {
        color[i]=1;
        bool ans=dfs(i);
        if(!ans)
        {
            is_biphartite=false;
            break;
        }

    }
}
if(!is_biphartite)
{
    cout<<"NO";
}
else
cout<<"yes";
    return 0;
}