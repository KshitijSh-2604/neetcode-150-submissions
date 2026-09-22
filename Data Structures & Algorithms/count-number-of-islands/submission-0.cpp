// DFS solution
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
                    dfs(grid, r, c);
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        int R = grid.size(), C = grid[0].size();
        if (r<0 || c<0 || r>=R || c>=C || grid[r][c]=='0')
        {
            return;
        }
        grid[r][c] = '0';
        for (int i=0; i<4; i++)
        {
            dfs(grid, r+dirs[i][0], c+dirs[i][1]);
        }
    }
};
