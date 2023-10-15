#include<bits/stdc++.h>
// chech cycle in a undirected graph.(unweighted graph)
using namespace std;
const int N=1e5;
vector<int>adjlist[N];
int visited[N];
int parent[N];
bool check_cycle(int src)
{
    visited[src]=1;
    parent[src]=-1;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int current_node=q.front();
        q.pop();
        for(auto adj_node:adjlist[current_node])
        {
            if(!visited[adj_node])
            {
                visited[adj_node]=1;
                parent[adj_node]=current_node;
                q.push(adj_node);
            }
            else if(visited[adj_node] && adj_node!=parent[current_node])
            {
                return true;
            }
        }
    }
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
adjlist[u].push_back(v);
adjlist[v].push_back(u);
}

int src=1;
bool ans=check_cycle(src);

if(ans)
{
    cout<<"cycle exits";

}
else
cout<<"NO cycle";
    return 0;
}