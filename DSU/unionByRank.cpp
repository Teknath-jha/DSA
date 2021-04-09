/*

#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
#define mod 1000000007
int parent[MAX] , Rank[MAX];
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
    memset(Rank, 1, sizeof(Rank));

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

*/

// Union byRank


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

