#include<bits/stdc++.h>

using namespace std;
const int N=1e2;
int arr[N];
vector<int>ans;
int main()
{
int n,target;
cin>>n>>target;

for(int i=1;i<=n;i++)
{
cin>>arr[i];
}

for(int i=1;i<=n-1;i++)
{

for(int j=i+1;j<=n;j++)
{
if(arr[i]+arr[j]==target)
{
cout<<i<<" "<< j;
break;

}

}
}
    return 0;
}