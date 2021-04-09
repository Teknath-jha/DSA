#include<bits/stdc++.h>
using namespace std;
int par[100005];

int find(int a)
{
    if(par[a]<0)
        return a;
    
    return par[a]=find(par[a]);
}

void merge(int a,int b)
{
    par[a]+=par[b];
    par[b]=a;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)par[i]=-1;

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;

        a=find(a);
        b=find(b);

        if(a!=b)
        merge(a,b);
    }

    for(int i=1;i<=n;i++)
    {
        int ans=find(i);
        cout<<-par[ans] -1 <<" ";

    }


    return 0;
}