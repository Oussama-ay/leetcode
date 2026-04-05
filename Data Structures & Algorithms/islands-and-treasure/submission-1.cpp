    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
class Solution {
    int n, m;
    struct triple {
        int x;
        int y;
        int d;
    };
    void bfs(vector<vector<int>>& grid, int i, int j)
    {
        vector<vector<bool>> v(n, vector<bool>(m, false));
        queue<triple> q;
        q.push({i, j, 0});
        v[i][j] = true;
        while (!q.empty())
        {
            triple cord = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = cord.x + dx[i];
                int y = cord.y + dy[i];
                if (x < 0 || y < 0 || x >= n || y >= m)
                    continue;
                if (grid[x][y] == -1 || grid[x][y] == 0 || v[x][y] || grid[x][y] <= cord.d + 1)
                    continue;
                v[x][y] = true;
                grid[x][y] = cord.d + 1;
                q.push({x, y, cord.d + 1});
            }
        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        n = grid.size();
        if (n == 0) return;
        m = grid[0].size();
        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++)
                if (grid[r][c] == 0)
                    bfs(grid, r, c);
    }
};
