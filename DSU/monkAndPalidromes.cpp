#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define Mod 1000000007
int par[MAX];


int find(int a)
{
    if(par[a]==a)
        return a;

    return par[a]=find(par[a]);
}

void merge(int a,int b)
{
    par[b]=a;
}


signed main()
{

    int n;cin>>n;
    for(int i=1;i<=n;i++)par[i]=i;

    int q;cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;


        int p=a , q=b;
        while(p<q){
        p=find(p);
        q=find(q);
        if(p!=q)
        merge(p,q);
        p++,q--;
        }
    }

    int count=0;

    for(int i=1;i<=n;i++)
    {
        if(par[i]==i)
        count++;
    }
long long int ans=1;
for(int i=1;i<=count;i++)
ans=((ans%Mod)*10)%Mod;


    cout<<ans%Mod<<endl;
}




///Ganesh

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 1e3 + 5;
const int mod = 1e9 + 7;

vector<ll> parent(maxN), ranking(maxN);

ll find(ll u) {
    if(parent[u] == u)
        return u;

    return parent[u] = find(parent[u]);
}

void Union(ll u, ll v) {
    int u_parent = find(u);
    int v_parent = find(v);

    if(u_parent != v_parent) {
        if(ranking[u_parent] < ranking[v_parent])
            parent[u_parent] = v_parent;
        else if(ranking[u_parent] > ranking[v_parent])
            parent[v_parent] = u_parent;
        else {
            parent[v_parent] = u_parent;
            ranking[u_parent]++;
        }
    }
}

ll bpower(ll a, ll b) {
    if(b == 0)
        return 0;
    else if(b == 1)
        return a;

    ll result = 1;

    while(b) {
        if(b&1)
            result = (result*a) % mod;
        b /= 2;
        a = (a*a) % mod;
    }

    return result;
}

int main() {
    ll N;
    cin >> N;

    for(ll i = 1; i <= N; i++) {
        parent[i] = i;
        ranking[i] = 0;
    }

    ll Q;
    cin >> Q;

    while(Q--) {
        ll u, v;
        cin >> u >> v;

        while(u < v) {
            Union(u, v);
            u++;
            v--;
        }
    }

    set<ll> s;

    for(ll i = 1; i <= N; i++)
        s.insert(find(i));

    ll count = s.size();

    ll answer = bpower(10, count);

    cout << answer << '\n';

    return 0;
}