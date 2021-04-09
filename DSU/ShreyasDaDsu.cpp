#include <bits/stdc++.h>
using namespace std;
const int maxs = 100006;

int PARENT[maxs];
int SIZE[maxs];
map<int,int>MP;

void SET(int V)
{
    PARENT[V] = V;
    SIZE[V] = 1;
    MP[V] = 1;
}

int FIND_SET(int V)
{
    if(V == PARENT[V])
        return V;
    else
        return PARENT[V] = FIND_SET(PARENT[V]);
}

void UNION(int A,int B)
{
    A = FIND_SET(A);
    B = FIND_SET(B);
    
    if(A != B)
    {
        if(SIZE[A] < SIZE[B])
            swap(A,B);
        PARENT[B] = A;
        SIZE[A] += SIZE[B];
        MP[A] += MP[B];
    }
}
 
signed main()
{

    ios_base::sync_with_stdio(0);   
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin >> n >> m;
    
    for(int i = 1;i <= n;++i)
        SET(i);
    
    map<int,pair<int,int>>mp;
    
    for(int i = 1;i <= m;++i)
    {
        int u,v;
        cin >> u >> v;
        mp[i] = {u,v};
    }
    
    int q;
    cin >> q;
    
    vector<int>A(q);
    
    map<int,int>isAsked;
    
    for(auto &it : A)
    {
            cin >> it;
            isAsked[it]++;
    }
    
    for(int i = 1;i <= m;++i)
    {
        int res = isAsked[i];
        if(res == 0)
            {
                auto it = mp[i];
                UNION(it.first,it.second);
            }
    }
    
    // for(int i = 1;i <= n;++i)
    // {
    //     int res = FIND_SET(i);
    // }
    
    // for(int i = 1;i <= n;++i)
    // {
    //     cout << MP[i] << " ";
    // }
    
    vector<int>X;
    
    while(!A.empty())
    {
        int val = A.back();
        A.pop_back();
        
        auto it = mp[val];
        
        int c1 = FIND_SET(it.first);
        int c2 = FIND_SET(it.second);
        
        int res = max(MP[PARENT[it.first]],MP[PARENT[it.second]]);
        
        int tmp = n - res + 1;
        
       // cout << val << " " << it.first << " " << it.second << " "  << res << " " << tmp << endl;
        
        X.push_back(tmp);
        // cout << res << " ";
        // for(int i = 1;i <= n;++i)
        // {
        //     cout << MP[i] << " ";
        // }
        
        // cout << endl;
        
        UNION(it.first,it.second);
        
    }
    
    reverse(X.begin(),X.end());
    
    for(int e : X)
        cout << e << " ";
    
    
}