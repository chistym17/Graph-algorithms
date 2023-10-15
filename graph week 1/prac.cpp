#include<bits/stdc++.h>
//convert adj matrix to adj list
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
cout<<"\n";
//convert to adj list
vector<int>list[n];
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        if(mat[i][j]==1)
        {
            list[i].push_back(j);
        }
    }
}

for(int i=0;i<n;i++)
{   cout<<i;
    for(auto val:list[i])
    {
        cout<<"->"<<val<<" ";
    }
    cout<<"\n";
}


    return 0;
}