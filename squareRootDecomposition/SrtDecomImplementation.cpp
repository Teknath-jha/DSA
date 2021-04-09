
// C++ program to demonstrate working of Square Root
// Decomposition.
#include <bits/stdc++.h>
using namespace std;

int arr[100005]; // original array
int block[100];  // decomposed array
int blk_sz;      // block size

// Time Complexity : O(1)
void update(int idx, int val)
{
    int blockNumber = idx / blk_sz;
    block[blockNumber] += val - arr[idx];
    arr[idx] = val;
}

// Time Complexity : O(sqrt(n))
int query(int l, int r)
{
    int sum = 0;
    while (l < r and l % blk_sz != 0 and l != 0)
    {
        // traversing first block in range
        sum += arr[l];
        l++;
    }
    while (l + blk_sz <= r)
    {
        // traversing completely overlapped blocks in range
        sum += block[l / blk_sz];
        l += blk_sz;
    }
    while (l <= r)
    {
        // traversing last block in range
        sum += arr[l];
        l++;
    }
    return sum;
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
        block[blk_idx] += arr[i];
    }
}

// Driver code
int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    preprocess(n);

    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<endl;
    }
    return 0;
}