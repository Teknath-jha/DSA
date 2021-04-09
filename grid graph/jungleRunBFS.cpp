#include <bits/stdc++.h>
using namespace std;
char grid[100][100];
int vis[100][100];
int dis[100][100];
int n;

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > n || grid[x][y] == 'T')
        return false;

    if (vis[x][y] == 1)
        return false;

    return true;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int srcX, int srcY)
{
    queue<pair<int, int>> q;
    vis[srcX][srcY] = 1;
    dis[srcX][srcY] = 0;
    q.push({srcX, srcY});

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

                vis[newX][newY] = 1;
                dis[newX][newY] = dis[currX][currY] + 1;
                q.push({newX, newY});
            }
        }
    }
}

int main()
{
    cin >> n;
    int startX, startY, endX, endY;

    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
                startX = i, startY = j;
            if (grid[i][j] == 'E')
                endX = i, endY = j;
        }
    }

    bfs(startX, startY);

    cout << dis[endX][endY] << '\n';


    //     for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
           
    //          cout<<dis[i][j]<<" ";
    //     }cout<<endl;
    // }


    return 0;
}