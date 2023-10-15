#include<bits/stdc++.h>
//all apir shortest path
using namespace std;
const int N=100;
const int INF=1e5;
int main()
{
int mat[N][N];
int n,m;
cin>>n,m;
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {mat[i][j]=INF;
    }
}

for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        mat[u][v]=w;
        
    }
}
for(int i=1;i<=n;i++)
{
    mat[i][i]=0;
}

for(int k=1;k<=n;k++)
{
    for(int u=1;u<=n;u++)
    {
        for(int v=1;v<=n;v++)
        {
            mat[u][v]=min(mat[u][v],mat[u][k]+mat[k][v]);

        }
    }
}
//print the matriix;

    return 0;
}