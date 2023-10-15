#include<bits/stdc++.h>

using namespace std;
int main()
{


int n=4;
int mat[n][n]={};

    for(int j=0;j<4;j++)
    {
        int a,b;
        cin>>a;
        cin>>b;
        mat[a][b]=1;
        mat[b][a]=1;
    }

for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        cout<<mat[i][j];
    }
    cout<<"\n";
}

    return 0;
}