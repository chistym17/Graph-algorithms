#include<bits/stdc++.h>
using namespace std;
const int N=100;
const int INF=1e4;
int main()
{
int n,m,q;
cin >> n >>m >>q;
int mat[N][N];
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {mat[i][j]=INF;
    }
}

for(int i=1;i<=m;i++)
{
        int u,v;
        cin>>u>>v;
         int w;
        cin>>w;
        mat[u][v]=min(mat[u][v],w);
        mat[v][u]=min(mat[v][u],w);
    
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
for(int i=0;i<q;i++)
{
    int u,v;
    cin>>u>>v;
    if(mat[u][v]==INF)
    {
        cout<<"-1"<<"\n";
        
    }
    else
    cout<<mat[u][v]<<"\n";
}

    return 0;
}
