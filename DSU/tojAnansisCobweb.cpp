#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
int par[MAX];
vector<pair<int, int>> edge;

int find(int a)
{
    if (par[a] == a)
        return a;
    return par[a] = find(par[a]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    par[b] = a;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        par[i] = i;

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        edge.push_back({a, b});
    }
    int q;
    cin >> q;

    vector<int> que;
    que.push_back(-1);
    int state[m];
    memset(state, 0, sizeof state);
    for (int i = 0; i < q; i++)
    {
        int r;
        cin >> r;
        state[r - 1] = 1;
        que.push_back(r);
    }

    int cnt = n;

    for (int i = 0; i < m; i++)
    {
        if (state[i - 1] == 0)
        {
            int first = edge[i].first;
            int second = edge[i].second;
            // if they are not part of same group make them friend :) and reduce the count
            if (find(first) != find(second))
            {
                cnt--;
                merge(edge[i].first, edge[i].second);
            }
        }
    }
    vector<int> ans;
    reverse(que.begin(), que.end());
    for (int i = 0; i < q; i++)
    {
        ans.push_back(cnt);

        int now = que[i] - 1;

        // if they are not part of same group make them friend :) and reduce the count
        if (find(edge[now].first) != find(edge[now].second))
        {
            cnt--;
            merge(edge[now].first, edge[now].second);
        }
    }

    reverse(ans.begin(), ans.end());

    for (int i : ans)
        cout << i << " ";

    return 0;
}