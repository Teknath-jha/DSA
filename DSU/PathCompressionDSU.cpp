#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
#define mod 1000000007
int parent[MAX];
int n;

//Path compression technique
//Iterative
int find(int a)
{
    vector<int> v;
    while (parent[a] > 0)
    {
        v.push_back(a);
        a = parent[a];
    }

    for (int x : v)
        parent[x] = a;

    return a;
}

//Recursive path compression
/*

int find(int a)
{
    if(parent[a]<0)
        return a;
    return parent[a] = find(parent[a]);
    
}

*/

void Union(int a, int b)
{
    parent[a] += parent[b];
    parent[b] = a;
}

//For debugging
void print()
{
    for (int i = 1; i <= n; i++)
        cout << i << " ";

    cout << endl;

    for (int i = 1; i <= n; i++)
        cout << parent[i] << " ";
    cout << endl;
}

int main()
{

    int m;
    cin >> n >> m;

    memset(parent, -1, sizeof(parent));

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        a = find(a);
        b = find(b);

        if (a != b)
            Union(a, b);
    }

    long long int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] < 0)
            ans = ((ans % mod) * ((-1) * (parent[i])) % mod) % mod;
    }

    cout << ans << endl;

    return 0;
}