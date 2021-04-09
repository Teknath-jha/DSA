#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
vector<int> adj[MAX];
vector<int> tr[MAX];

int vis[MAX];
vector<int> order , scc;

void dfs(int src)
{
    vis[src] = 1;

    for (auto nb : adj[src])
        if (vis[nb] == 0)
            dfs(nb);

    order.push_back(src);
}


void dfs1(int src)
{
    vis[src] = 1;

    for (auto nb : adj[src])
        if (vis[nb] == 0)
            dfs(nb);

    scc.push_back(src);
}

int main()
{

        int n, m;
        
        cin >> n >> m;
        int ans[n+1];
        memset(ans,0,sizeof ans);

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
        
        memset(vis,0,sizeof(vis));

        reverse(order.begin(),order.end());
        for(int i:order)
        {
            if(vis[i]==0)
            {
                scc.clear();

                dfs1(i);

                if(scc.size()>1)
                {
                    for(int x:scc)
                        ans[x]=1;
                }
            }
        }

        for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    

    return 0;
}
