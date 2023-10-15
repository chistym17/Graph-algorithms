#include<bits/stdc++.h>

using namespace std;
const int N=5000;
int mat[N][N];
int visited[N][N];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int n,m;
int level[N][N]={-1};

bool is_inside(pair<int,int>cord)
{
    int x=cord.first;
    int y=cord.second;
    if(x>=0 && x<n && y>=0 && y<m)
    {
        return true;
    }
    return false;

    
}
bool is_not_forbidden(pair<int,int>cord)
{
    int x=cord.first;
    int y=cord.second;
    if(mat[x][y]==-1)
    {
        return true;
    }
    return false;

}

void bfs(pair<int,int>src)
{
    queue<pair<int,int>>q;
    visited[src.first][src.second]=1;
    q.push(src);
    level[src.first][src.second]=0;
    while (!q.empty())
    {
        
        pair<int,int>h=q.front();
        q.pop();
        int x=h.first;
        int y=h.second;
        for(int i=0;i<4;i++)
        {
            int new_x=x+dx[i];
            int new_y=y+dy[i];
            pair<int,int>adj_node={new_x,new_y};
            if(is_inside(adj_node) && is_not_forbidden(adj_node) && visited[new_x][new_y]==0)
            {
                visited[new_x][new_y]=1;
                level[new_x][new_y]=level[x][y]+1;
                q.push(adj_node);

            }
        }

    }
    


}
int main()
{
cin>>n;
cin>>m;
pair<int,int>src,dst;
for(int i=0;i<n;i++)
{
    string input;
    cin>>input;
    for(int j=0;j<m;j++)
    {
        if(input[j]=='#')
        {
            mat[i][j]=-1;
        }
        else if(input[j]=='A'){
            src={i,j};

        }
        
        else if(input[j]=='B'){
            dst={i,j};

    }
}


}

if(level[dst.first][dst.second]==-1)
{
    cout<<":NO";
}
else
cout<<"yes";

cout<<"\n";
cout<<level[dst.first][dst.second]<<" ";


    return 0;
}