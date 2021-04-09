#include <bits/stdc++.h>
using namespace std;

#define MAX 10005
vector<int> adj[MAX]; // graph
vector<int> tr[MAX];  //transpose graph

vector<int> order;
vector<int> SCC; //strongly connected components

int vis[MAX];

void dfs(int src)
{
    vis[src] = 1;

    for (auto nb : adj[src])
    {
        if (vis[nb] == 0)
            dfs(nb);
    }

    order.push_back(src);
}

void dfs1(int src)
{
    vis[src] = 1;
    for (auto nb : tr[src])
        if (vis[nb] == 0)
            dfs1(nb);

    SCC.push_back(src);
}

int main()
{
    cout<<"Enter test cases : ";
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
            adj[i].clear(), tr[i].clear(), vis[i] = 0;
        order.clear();

        for (int i = 1; i <= m; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            tr[b].push_back(a);
        }

        for (int i = 1; i <= n; i++)
            if (vis[i] == 0)
                dfs(i);

        for (int i = 1; i <= n; i++)
            vis[i] = 0;

        reverse(order.begin(),order.end());

        for (int i:order)
        {
            if (vis[i] == 0)
            {
                SCC.clear();
                dfs1(i);

                cout << "dfs1() called from " << i << " and printing SCC\n";
                for (int node : SCC)
                    cout << node << " ";
                cout << endl;
            }
        }
    }

    return 0;
}