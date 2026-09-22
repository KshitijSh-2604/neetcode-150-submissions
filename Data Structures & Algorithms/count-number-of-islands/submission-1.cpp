// BFS solution
class Solution {
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size(), C = grid[0].size();
        int ans = 0;
        for (int r=0; r<R; r++)
        {
            for (int c=0; c<C; c++)
            {
                if (grid[r][c] == '1')
                {
                    bfs(grid, r, c);
                    ans++;
                }
            }
        }
        return ans;
    }
    void bfs(vector<vector<char>>& grid, int r, int c)
    {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0';
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            int row = node.first, col = node.second;
            for (int i=0; i<4; i++)
            {
                int nr = row + dirs[i][0];
                int nc = col + dirs[i][1];
                if (nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]=='1')
                {
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};
