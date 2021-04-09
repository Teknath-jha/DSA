#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

struct  node
{
    int arr[3];
};


int arr[MAX];
node st[4*MAX] ;
int  lazy[4*MAX];


void segTree(int si,int ss,int se)
{
    if(ss==se)
    {
        st[si].arr[0]=1;
        st[si].arr[1]=0;
        st[si].arr[2]=0;
        return ;   
    }

    int mid = ss+(se-ss)/2;

    segTree(2*si,ss,mid);
    segTree(2*si+1,mid+1,se);

    st[si].arr[0] = st[2*si].arr[0] + st[2*si+1].arr[0];
    st[si].arr[1] = st[2*si].arr[1] + st[2*si+1].arr[1];
    st[si].arr[2] = st[2*si].arr[2] + st[2*si+1].arr[2];
}

void shift(int si)
{
    int a = st[si].arr[2];

    st[si].arr[2]=st[si].arr[1];
    st[si].arr[1]=st[si].arr[0];
    st[si].arr[0]= a;
}

void update(int si,int ss,int se,int qs,int qe,int val=1)
{
    if(lazy[si]!=0)  //pending updates
    {
        int add=lazy[si];
        lazy[si]=0;
        if(ss!=se)
        {
            lazy[2*si]+=add;
            lazy[2*si+1]+=add;
        }
        
        add =add % 3;
        for(int i=0;i<add;i++)
            shift(si);
    }

    if(ss>qe || se<qs)
    return;

    if(ss>=qs && se<=qe )
    {
        shift(si);
        if(ss!=se)
        {
            lazy[2*si]+=val;
            lazy[2*si+1]+=val;
        }
        return;
    }
    int mid=ss+(se-ss)/2;

    update(2*si,ss,mid,qs,qe,val);
    update(2*si+1,mid+1,se,qs,qe,val);

    st[si].arr[0] = st[2*si].arr[0] + st[2*si+1].arr[0];
    st[si].arr[1] = st[2*si].arr[1] + st[2*si+1].arr[1];
    st[si].arr[2] = st[2*si].arr[2] + st[2*si+1].arr[2];
}

int query(int si , int ss,int se, int qs , int qe)
{
    if(lazy[si]!=0)  //pending updates
    {
        int add=lazy[si];
        lazy[si]=0;
        if(ss!=se)
        {
            lazy[2*si]+=add;
            lazy[2*si+1]+=add;
        }
        
        add =add% 3;
        for(int i=0;i<add;i++)
            shift(si);
    }

    if(ss>qe || se<qs)
    return 0;

    if(ss>=qs && se<=qe )
    {
        return st[si].arr[0];
    }

    int mid = ss+(se-ss)/2;

    int l=query(2*si,ss,mid,qs,qe);
    int r=query(2*si+1,mid+1,se,qs,qe);

    return(l+r);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n;cin>>n;
    int q;cin>>q;

    segTree(1,1,n);


    while(q--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(x==0)
        {
            update(1,1,n,y+1,z+1);
        }
        else 
        {
            cout<<query(1,1,n,y+1,z+1)<<'\n';
        }
    }
}