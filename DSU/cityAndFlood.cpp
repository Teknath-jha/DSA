#include<bits/stdc++.h>
using namespace std ;

#define MAX 1000005
int par[MAX];


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
    if(a!=b)
    par[b]=a;
    
}


signed main()
{
    for(int i=1;i<MAX;i++)
        par[i]=i;
    int n;cin>>n;

    int q;cin>>q;
    while(q--)
    {
        int a,b;cin>>a>>b;
        union_(a,b);
    }
    set<int> st;

    for(int i=1;i<=n;i++)
    st.insert(find(i));

    cout<<st.size()<<'\n';

}
