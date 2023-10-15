#include<bits/stdc++.h>
using namespace std;
//print the negative cycle.
const int N=1e4;
const int INF=1e6;
vector<pair<int,int>>adjlist[N];
int dis[N]={INF};
int parent[N];


int main()
{
int nodes,edges;
cin>>nodes>>edges;
for(int i=0;i<edges;i++)
{
int u,v,w;
cin>>u>>v>>w;
adjlist[u].push_back({v,w});

}
int last_updated_node=-1;
bool check_cycle=false;
int src=1;
parent[src]=-1;
for(int i=1;i<=nodes;i++)
{
    for(int j=1;j<=nodes;j++)
    {
        for(auto adj_node:adjlist[j])
        {
            int u=j;
            int v=adj_node.first;
            int w=adj_node.second;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                parent[v]=u;
                if(i==nodes){
                check_cycle=true;
                last_updated_node=v;

                }
            }
        }
    }
}

if(check_cycle)cout<<"cycle exists";
else cout<<"NO cycle";
cout<<"\n";
int selected_node=last_updated_node;
for(int i=1;i<=nodes-1;i++)
{
    selected_node=parent[selected_node];

}
vector<int>cycle;
cycle.push_back(selected_node);
while(1)
{
    selected_node=parent[selected_node];
    cycle.push_back(selected_node);
    if(selected_node==last_updated_node)
    break;
}

reverse(cycle.begin(),cycle.end());

for(auto a:cycle)
{
    cout<<a<<" ";
}
        
return 0;

}
