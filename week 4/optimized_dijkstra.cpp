#include<bits/stdc++.h>

using namespace std;
const int N=1e5;
const long long int INF=1e18;
int nodes,edge;
vector<pair<int,int>>adjlist[N];
int visited[N]={0};
long long int d[N]={INF};
int parent[N];


void dijkastra(int src)
{

d[src]=1;
visited[src]=1;
priority_queue<pair<long long,int>>pq;
pq.push({0,src});
int selected;
while(!pq.empty())
{
    pair<long long,int>p=pq.top();
    pq.pop();
     selected=p.second;
    if(visited[selected])continue;
    visited[selected]=1;

}

    
    for(auto adj:adjlist[selected])
    {
        int dis=adj.first;
        int cost=adj.second;
        if(d[selected]+cost< d[dis])
    
        {
            d[dis]=d[selected]+cost;
            parent[dis]=selected;
            pq.push({-d[dis],dis});

        }
    }
}




int main()
{
cin>>nodes>>edge;

for(int i=0;i<edge;i++)
{
    int u,v,w;
    cin>>u>>v>>w;
    adjlist[u].push_back({v,w});
    adjlist[v].push_back({u,w});
}
int src=1;



    return 0;
}