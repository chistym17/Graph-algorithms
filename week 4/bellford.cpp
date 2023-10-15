#include<bits/stdc++.h>
using namespace std;

const int N=1000;
vector<pair<int,int>>adjlist[N];
int dis[N]={N};



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

for(int i=0;i<nodes-1;i++)
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


            }
        }
    }
}




}