#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int st[400005];

void segTree(int si, int ss, int se)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return;
    }

    int mid = (ss + se) / 2;

    segTree(2 * si, ss, mid);
    segTree(2 * si + 1, mid + 1, se);

    st[si] = min(st[2 * si], st[2 * si + 1]);
}

void update(int si,int ss, int se,int qe)
{
    if(ss == se)
    {
        st[si]=arr[qe];
        return;
    }

    int mid = (ss+se)/2;

    if(qe <= mid) update(2*si,ss,mid,qe);
    else          update(2*si+1,mid+1,se,qe);

    st[si]=min(st[2*si],st[2*si+1]);
}

int query(int si, int ss,int se ,int qs, int qe)
{
    if(se < qs || ss > qe)
    {
        return INT_MAX;
    }
    if(ss>=qs && se<=qe)
        return st[si];
    
    int mid= (ss+se)/2;

    int l=query(2*si,ss,mid,qs,qe);
    int r=query(2*si+1,mid+1,se,qs,qe);

    return min(l,r);
}

signed main()
{
    cout<<"Enter n : ";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    segTree(1,1,n);
    cout<<"Enter q : ";
    int q;
    cin >> q;
    while (q--)
    {
        char op;
        int l, r;
        cin >> op;

        if (op == 'u')
        {
            int at , value;
            cin>>at>>value;
            arr[at]=value;
            update(1,1,n,at);
        }
        if (op == 'f')
        {
            int l,r;
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<'\n';
        }
    }
}