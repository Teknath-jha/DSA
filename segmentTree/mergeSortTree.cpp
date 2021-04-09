//form some problems segment tree is not enough so we learn this merge sort tree
//space complexity NlogN
//Time complexity
//QUESTION :  find no. of elements strictly less than k in range l to r in an array

#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
int arr[MAX];
vector<int> st[4 * MAX];

//building a merge sort tree
void build(int si, int ss, int se)
{
    if (ss == se)
    {
        st[si].push_back(arr[ss]);
        return;
    }

    int mid = ss + (se - ss) / 2;
    build(2 * si, ss, mid);
    build(2 * si + 1, mid + 1, se);

    //now bleow is simple basic  merge sort algo
    int i = 0;
    int j = 0;

    while (i < st[2 * si].size() && j < st[2 * si + 1].size())
    {
        if (st[2 * si][i] <= st[2 * si + 1][j])
            st[si].push_back(st[2 * si][i]), i++;

        else
            st[si].push_back(st[2 * si + 1][j]), j++;
    }

    while (i < st[2 * si].size())
        st[si].push_back(st[2 * si][i]), i++;

    while (j < st[2 * si + 1].size())
        st[si].push_back(st[2 * si + 1][j]), j++;
}

int query(int si, int ss, int se, int qs, int qe, int k)
{
    if (ss > qe || se < qs)
        return 0;

    if (ss >= qs && se <= qe)
    { //logN
        int res = upper_bound(st[si].begin(), st[si].end(), k - 1) - st[si].begin();
        return res;
    }

    int mid = ss + (se - ss) / 2;

    int l = query(2 * si, ss, mid, qs, qe, k);
    int r = query(2 * si + 1, mid + 1, se, qs, qe, k);

    return l + r;
}

signed main()
{
    int n, q, l, r, k;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    build(1, 1, n);

    cout << "Enter q : " << '\n';
    cin >> q;
    while (q--)
    {
        cout << "Enter l r k : ";
        cin >> l >> r >> k;
        cout << query(1, 1, n, l, r, k) << '\n';
    }
}