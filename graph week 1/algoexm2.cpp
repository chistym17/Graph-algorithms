#include<bits/stdc++.h>

using namespace std;
int calpower(int n,int m)
{
    if(m==0)return 1;
    else
    return n*calpower(n,m-1);
}
int main()
{

int n,m;
cout<<"Enter base number";
cin>>n;
cout<<"enter power";
cin>>m;
int ans=calpower(n,m);
cout<<ans;


    return 0;
}