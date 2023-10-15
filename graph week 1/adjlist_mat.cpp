#include<bits/stdc++.h>

using namespace std;
int main()
{
int n=4;
vector<int>list[n];
for(int i=0;i<n;i++)
{
    int a;
    int b;
    cin>>a;
    cin>>b;
    list[a].push_back(b);
    list[b].push_back(a);
}
cout<<"\n";
int mat[n][n]={};

for(int i=0;i<n;i++)
{
    cout<<i<<"->";
    for(auto val:list[i])
    {
        cout<<val<<" ";
    }
    cout<<"\n";
}
//convert to matrix
for(int i=0;i<n;i++)
{
    for(auto val:list[i])
    {
        mat[i][val]=1;

    }

}


for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        cout<<mat[i][j]<<" ";
    }
    cout<<"\n";
}

    return 0;
}