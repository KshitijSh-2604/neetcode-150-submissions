class Solution {
  public:
    int longestConsecutive(vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        set<int> S;
        int Max = 0, local_Max = 0;
        for (int i=0; i<nums.size(); i++)
        {
            S.insert(nums[i]);
        }
        vector<int> V(S.begin(), S.end());
        for(int i=1; i<V.size(); i++)
        {
            if(V[i]-V[i-1] == 1)
            {
                local_Max++;
                if(Max < local_Max)
                {
                    Max = local_Max;
                }
            }
            else
            {
                local_Max = 0;
            }
        }
        return Max + 1;
    }
};