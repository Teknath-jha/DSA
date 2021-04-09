#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
int arr[100005];
int st[400001];

void segTree(int si, int ss, int se)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return;
    }

    int mid = (se + ss) / 2;

    segTree(2 * si, ss, mid);
    segTree(2 * si + 1, mid + 1, se);

    st[si] = min(st[2 * si], st[2 * si + 1]);
}

int query(int si, int ss, int se, int qs, int qe)
{
    if (qs > se || qe < ss)
        return INT_MAX;

    if (ss >= qs && se <= qe)
        return st[si];
    
    int mid = ss + (se - ss) / 2;
    int l = query(2 * si, ss, mid, qs, qe);
    int r = query(2 * si + 1, mid + 1, se, qs, qe);

    return min(l, r);
}

signed main()
{
    // cout << "Enter ee n\n";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];


    segTree(1, 1, n);
    int q;

    // cout << "Enter q:\n";
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, n, l+1, r+1)<<'\n';
    }
}