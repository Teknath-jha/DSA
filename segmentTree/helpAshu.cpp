#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int arr[100005];
pair<int,int> st[400005];


void segTree(int si,int ss,int se)
{
    if(ss==se)
    {
        if(arr[ss]&1)
        st[si]={1,0};
        else 
        st[si]={0,1};

        return ;
    }

    int mid = (ss+(se-ss)/2);

    segTree(2*si,ss,mid);
    segTree(2*si+1,mid+1,se);

    st[si].first=st[2*si].first+st[2*si+1].first;
    st[si].second=st[2*si].second+st[2*si+1].second;  
    
}

pair<int,int>  query(int si ,int ss, int se,int qs,int qe)
{
    if(ss > qe || se  < qs) //outside pura
    return {0,0};

    if(ss>=qs && se<=qe)  // inside pura 
    {
        return st[si];
    }

    int mid=ss+(se-ss)/2;

    pair<int,int> l=query(2*si,ss,mid,qs,qe);
    pair<int,int> r=query(2*si+1,mid+1,se,qs,qe);

    l.first=l.first+r.first;
    l.second=l.second+r.second;

    return l;
}

void update(int si,int ss,int se,int qi)
{
    if(ss==se)
    {
        if(arr[qi]&1)
        st[si]={1,0};
        else 
        st[si]={0,1};
        return;
    }

    int mid = ss+(se-ss)/2;

    if(qi <= mid) update(2*si,ss,mid,qi);
    else         update(2*si+1,mid+1,se,qi);

    st[si].first=st[2*si].first+st[2*si+1].first;
    st[si].second=st[2*si].second+st[2*si+1].second; 

}

signed main()
{

int n;cin>>n;
for(int i=1;i<=n;i++)
    cin>>arr[i];

segTree(1,1,n);


int q;cin>>q;

while(q--)
{
    int x,y,z;
    cin>>x>>y>>z;

    if(x==0)
    {
        arr[y]=z;
        update(1,1,n,y);
        
    }
    else if(x==1)
    {
        pair<int,int> p=query(1,1,n,y,z);
        cout<<p.second<<'\n';
    }
    else
    {
        pair<int,int> p=query(1,1,n,y,z);
        cout<<p.first<<'\n';
    }
}

}