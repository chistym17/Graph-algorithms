#include<bits/stdc++.h>

using namespace std;
const int N=1e5;
const int INF=1e9;
int nodes,edge;
vector<pair<int,int>>adjlist[N];
int visited[N]={0};
int d[N]={INF};


void dijkastra(int src)
{

d[src]=1;
visited[src]=1;
for(int i=1;i<=nodes;i++)
{
    int selected=-1;
    for(int j=1;j<=nodes;j++)
    {
        if(visited[j]==1)continue;
        
        if(selected =-1 || d[selected]>d[j])
        {
            selected=j;
        }
        
    }
    visited[selected]=1;
    for(auto adj:adjlist[selected])
    {
        int dis=adj.first;
        int cost=adj.second;
        if(d[selected]+cost< d[dis])
    
        {
            d[dis]=d[selected]+cost;

        }
    }
}



}
int main()
{
cin>>nodes>>edge;

for(int i=0;i<edge;i++)
{
    int u,v,w;
    cin>>u>>v,w;
    adjlist[u].push_back({v,w});
    adjlist[v].push_back({u,w});
}
int src=1;

dijkastra(src);
for(int i=0;i<nodes;i++)
{
    cout<<d[i]<<" ";
}

    return 0;
}