#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int vis[MAX][MAX];
int n, m;
bool isValid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;

    if (vis[x][y] == 1)
        return false;

    return true;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int x, int y)
{
    vis[x][y] = 1;

    cout << x << " " << y << '\n';

    for (int i = 0; i < 4; i++)
        if (isValid(x + dx[i], y + dy[i]))
            dfs(x + dx[i], y + dy[i]);
}

int main()
{
    n = 3, m = 3;
    vis[3][3];
    memset(vis, 0, sizeof(vis));

    dfs(0, 0);

    return 0;
}