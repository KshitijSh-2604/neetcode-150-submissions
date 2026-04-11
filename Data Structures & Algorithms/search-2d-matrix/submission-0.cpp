class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i=0; i<n; i++)
        {
            if (matrix[i][m-1] == target)
            {
                return true;
            }
            else if (matrix[i][m-1] < target)
            {
                continue;
            }
            else
            {
                int l = 0, r = m-1;
                while (l <= r)
                {
                    int mid = l+((r-l)/2);
                    if (matrix[i][mid] == target)
                    {
                        return true;
                    }
                    else if (matrix[i][mid] < target)
                    {
                        l = mid+1;
                    }
                    else
                    {
                        r = mid-1;
                    }
                }
                i = n;
            }
        }
        return false;
    }
};
