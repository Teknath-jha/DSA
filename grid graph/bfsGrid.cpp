//bfs traversal 
//counting components using bfs


#include <bits/stdc++.h>
using namespace std;

#define MAX 1001
int vis[MAX][MAX], dis[MAX][MAX];
int  grid[MAX][MAX];
int n, m;

bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return false;

    if (vis[x][y] == 1 || grid[x][y] == 0)
        return false;

    return true;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int srcX, int srcY)
{
    queue<pair<int, int>> q;
    q.push({srcX, srcY});
    dis[srcX][srcY] = 0;
    vis[srcX][srcY] = 1;

    while (!q.empty())
    {
        auto t = q.front();
        int currX = t.first;
        int currY = t.second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            if (isValid(currX + dx[i], currY + dy[i]))
            {
                int newX = currX + dx[i];
                int newY = currY + dy[i];

                dis[newX][newY] = dis[currX][currY] + 1;
                vis[newX][newY] = 1;
                q.push({newX, newY});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
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
            if (vis[i][j] == 0 && grid[i][j] == 1)
            {
                bfs(i, j);
                component++;
            }
        }
    }

    cout << "No. of components : " << component << endl;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}
