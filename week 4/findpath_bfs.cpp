#include<bits/stdc++.h>

using namespace std;
const int N=100;
vector<int>adjlist[N];
int visited[N];
int parent[N];
int level[N];

void bfs(int src)
{
    visited[src]=1;
    parent[src]=-1;
    level[src]=1;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {   
        int head=q.front();
        q.pop();
        for(auto a:adjlist[head])
        {
            if(visited[a]==0)
            {   level[a]=level[head]+1;
                visited[a]=1;
                parent[a]=head;
            }
        }

    }
}
int main()
{int dest;//input destination nite hobe

int nodes,edge;
dest=nodes;
cin>>nodes>>edge;

for(int i=0;i<edge;i++)
{
    int u,v;
    cin>>u>>v;
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
}
int src=1;
bfs(src);
// level print 
vector<int>path;
int selected=dest;
while(1)
{
    path.push_back(selected);
    if(selected==src)
    {
        break;;
    }
    selected=parent[selected];

}
reverse(path.begin(),path.end());
for(auto a:path)
{
    cout<<a<<" ";
}

    return 0;
}