#include<bits/stdc++.h>

using namespace std;
vector<int> adjlist[100];
int visited[100]={0};
int level[100]={0};
void bfs(int src)
{   
    queue<int>q;
    visited[src]=1;
    q.push(src);
    level[src]=0;
    while(!q.empty())
    {   
        int head=q.front();
        q.pop();
        for(auto v:adjlist[head])
        {
            if(visited[v]==0)
            {   level[v]=level[head]+1;
                visited[v]=1;
                q.push(v);

            }
        }




    }
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
int src=0;
bfs(src);
for(int i=0;i<nodes;i++)
{
    cout<<"Node-"<<i<<"->"<<level[i];
    cout<<"\n";
}
    return 0;
}