class Solution {
public:
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int time=0, fresh=0;
        int R = grid.size(), C = grid[0].size();
        for (int r=0; r<R; r++)
        {
            for (int c=0; c<C; c++)
            {
                if (grid[r][c] == 2)
                {
                    q.push({r,c});
                }
                if (grid[r][c] == 1)
                {
                    fresh++;
                }
            }
        }
        while (!q.empty() && fresh > 0)
        {
            int l = q.size();
            for (int i=0; i<l; i++)
            {
                auto node = q.front();
                q.pop();
                int row = node.first, col = node.second;
                for (int i=0; i<4; i++)
                {
                    int r = row+dirs[i][0], c = col+dirs[i][1];
                    if(r>=0 && c>=0 && r<R && c<C && grid[r][c]==1)
                    {
                        grid[r][c] = 2;
                        q.push({r,c});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh==0 ? time : -1;
    }
};
