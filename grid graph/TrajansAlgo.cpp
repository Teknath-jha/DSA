//tarjan's algo reduce the dfs call as compared to kosaraju's algo 
// and provide the same output 

#include<bits/stdc++.h>
using namespace std;

#define MAX 10005
vector<int> adj[MAX];
int vis[MAX];
int Onstack[MAX];
stack<int> stk;
int low[MAX], tin[MAX];
int scc=0;
int timer=1;

void dfs(int src)
{
    vis[src]=1;
    tin[src]=low[src]=timer++;
    Onstack[src]=1;
    stk.push(src);

    for(int nb:adj[src])
    {
        if(vis[nb]==1 && Onstack[nb]==1)
        {
            low[src]= min(low[src],tin[nb]);
        }
        else if(vis[nb]==0)
        {

            dfs(nb);

            if(Onstack[nb]==1)
            {
                low[src]= min(low[src],low[nb]);
            }
        }
    }

    if(tin[src]==low[src])
    {
        scc++;
        cout<<"SCC # "<<scc<<endl;

        int temp;
        while(1)
        {
            temp=stk.top();
            stk.pop();
            Onstack[temp]=0;
            cout<<temp<<" ";

            if(temp==src) break;
        }
        cout<<endl;
    }


}


int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        adj[i].clear(), vis[i]=0;
    
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }

    for(int i=1;i<=n;i++)
    if(vis[i]==0)
    dfs(i);

    return 0;
}