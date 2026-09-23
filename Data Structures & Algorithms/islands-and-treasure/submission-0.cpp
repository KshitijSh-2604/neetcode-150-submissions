class Solution {
public:
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        queue<pair<int, int>> q;
        for (int r=0; r<R; r++)
        {
            for (int c=0; c<C; c++)
            {
                if (grid[r][c] == 0)
                {
                    q.push({r,c});
                }
            }
        }
        int dist = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i=0; i<size; i++)
            {
                auto node = q.front();
                q.pop();
                int row = node.first, col = node.second;
                for (int i=0; i<4; i++)
                {
                    int r = row+dirs[i][0], c = col+dirs[i][1];
                    if (r<0 || r>=R || c<0 || c>=C || grid[r][c]!=INT_MAX)
                    {
                        continue;
                    }
                    grid[r][c] = grid[row][col]+1;
                    q.push({r,c});
                }
            }
        }
    }
};
