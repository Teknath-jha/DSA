
// C++ program to demonstrate working of Square Root
// Decomposition.
#include <bits/stdc++.h>
using namespace std;

int arr[100005]; // original array
int block[1000];  // decomposed array
int blk_sz;      // block size


// Time Complexity : O(sqrt(n))
int query(int l, int r)
{
    int ans = INT_MAX;
    while (l < r and l % blk_sz != 0 and l != 0)
    {
        // traversing first block in range
        ans=min(ans,arr[l]);
        l++;
    }
    while (l + blk_sz <= r)
    {
        // traversing completely overlapped blocks in range
        ans=min(ans,block[l/blk_sz]);
        l += blk_sz;
    }
    while (l <= r)
    {
        // traversing last block in range
        ans=min(ans,arr[l]);
        l++;
    }
    return ans;
}

// Fills values in input[]
void preprocess(int n)
{
    // initiating block pointer
    int blk_idx = -1;

    // calculating size of block
    blk_sz = sqrt(n);

    for (int i = 0; i < n; i++)
    {
        if (i % blk_sz == 0)
        {

            blk_idx++;
        }
        block[blk_idx] =min(block[blk_idx], arr[i]);
    }
}

// Driver code
int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    for(int i=0;i<1000;i++)block[i]=INT_MAX;
    preprocess(n);

    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<'\n';
    }
    return 0;
}