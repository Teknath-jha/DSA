#include <bits/stdc++.h>
using namespace std;

#define MAX 1001
int vis[MAX][MAX];
char grid[MAX][MAX];
int n, m;
bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m )
        return false;

    if (vis[x][y] == 1  || grid[x][y] == '#')
        return false;

    return true;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int x, int y)
{
    vis[x][y] = 1;

    // cout << x << " " << y << '\n';

    for (int i = 0; i < 4; i++)
        if (isValid(x + dx[i], y + dy[i]))
            dfs(x + dx[i], y + dy[i]);
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>grid[i][j];
        }
    }
    memset(vis, 0, sizeof(vis));

    
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //         cin>>grid[i][j];
    // }
    int component = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (vis[i][j] == 0 && grid[i][j] == '.')
            {
                dfs(i, j);
                component++;
            }
        }
    }

    cout<<component<<endl;

    return 0;
}

/*

0 0 1 0 1 1 
0 1 1 0 0 1
0 1 0 0 0 0 
1 0 1 1 0 0  
0 0 0 1 0 0
0 1 1 0 1 1


No. of components : 6

*/