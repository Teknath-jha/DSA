//sum of range between l to r

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int arr[MAX];
int st[4*MAX] , lazy[4*MAX];

void segTree(int si,int ss,int se)
{
    if(ss==se)
    {
        st[si]=arr[ss];
        return ;
    }

    int mid = ss+(se-ss)/2;

    segTree(2*si,ss,mid);
    segTree(2*si+1,mid+1,se);

    st[si]=st[2*si]+st[2*si+1];
}

int query(int si,int ss,int se,int qs,int qe)
{
    if(lazy[si]!=0)
    {
        int dx=lazy[si];
        lazy[si]=0;
        st[si]+=dx*(qe-qs+1);
        
        
        //updating left and right child of node in lazy tree
        if(ss!=se)
        {
            lazy[2*si]+=dx;
            lazy[2*si+1]+=dx;
        }
    }

    if(ss > qe || se < qs)  //outside hai pura
    return 0;

    if(ss>=qs && se<=qe )  ////inside hai pura
    {
        return st[si];
    }

    int mid = ss+(se-ss)/2;

    int l =query(2*si,ss,mid,qs,qe);
    int r =query(2*si+1,mid+1,se,qs,qe);

    return (r+l);  //kyuki sum of range pucha tha 

}

void update(int si,int ss,int se,int qs,int qe,int val)
{
    //checking for previous update
    if(lazy[si]!=0)
    {
        int dx=lazy[si];
        lazy[si]=0;
        st[si]+=dx*(qe-qs+1);
        
        if(ss!=se)
        {
            lazy[2*si]+=dx;
            lazy[2*si+1]+=dx;
        }
    }

    if(ss>qe || se<qs)
    return;

    //instead of updating at all segment tree just 
    //keeping record in lazy tree .
    if(ss>=qs&&se<=qe)
    {
        int dx=(se-ss+1)*val;
        st[si]+=dx;  //updating only main node in segment tree

        if(ss!=se)
        {
            lazy[2*si]+=val; //noted in left child lazy tree
            lazy[2*si+1]+=val; //noted in right child of lazy tree
        }
        return;
    }

    int mid=ss+(se-ss)/2;
    update(2*si,ss,mid,qs,qe,val);
    update(2*si+1,mid+1,se,qs,qe,val);

    st[si]=st[2*si]+st[2*si+1];
}

signed main()
{
    cout<<"Enter n : ";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    

//building segment Tree
    segTree(1,1,n);

    int q;
    cout<<"Enter q : ";
    cin>>q;

    while(q--)
    {
        int op;
        cin>>op;
        //query sum
        if(op==1)
        {
            int l,r;
            cout<<"l r : ";
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<'\n';
        }
        //update range 
        else if(op==2)
        {
            int l,r,val;
            cout<<"l r val: ";
            cin>>l>>r>>val;
            update(1,1,n,l,r,val);
            cout<<"\nUpdated\n";
        }
        else 
            cout<<"\nInvalid option\n";

    }
}