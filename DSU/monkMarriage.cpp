#include<bits/stdc++.h>
using namespace std;

#define MAX 2000005
int par[MAX];
int mens[MAX];
int womens[MAX];
const int incrementer = 1000001;
int find(int a)
{
    if(par[a]==a)
        return a;
    
    return par[a]=find(par[a]);
}

void union_(int a,int b)
{
    a=find(a);
    b=find(b);

    if(a==b)
    return ;

    par[b]=a;

    mens[a]+=mens[b];
    womens[a]+=womens[b];
}

signed main()
{

    int m,w;
    cin>>m>>w;


    for(int i =1;i<=MAX;i++)
    {
        par[i]=i;
        if(i<=10000001)
        mens[i]=1;
        else womens[i]=1;
    }
    int q1;cin>>q1;
    while(q1--)
    {
        int m1,m2;
        cin>>m1>>m2;

        union_(m1,m2);
    }

    int q2;cin>>q2;
    while(q2--)
    {
        int w1,w2;cin>>w1>>w2;

        w1+=incrementer;
        w2+=incrementer;

        union_(w1,w2);
    }
    
    int q3;cin>>q3;
    while(q3--)
    {
        int m1,w1;cin>>m1>>w1;
        w1+=incrementer;
        union_(m1,w1);
    }


    map<int ,int > mp;
    for(int i=1;i<=m;i++)
    {
        mp[find(i)]++;
    }


    int ans=0;

    for(auto x:mp)
    {
        int mns=mens[x.first];
        int wms=w-womens[x.first];

        ans+=(mns*wms);
    }

    cout<<ans<<'\n';


}