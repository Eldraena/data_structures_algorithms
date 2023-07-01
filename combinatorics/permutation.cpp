class Solution {
public:
    void per(vector<int>& nums, vector<vector<int>>& res, vector<pair<int, int>> &mark, int k)
    {
        if(k == nums.size())
        {
            res.push_back(nums);
            return;
        }

        for(int i = 0; i < mark.size(); i++)
        {
            if(mark[i].second == 0)
            {
                mark[i].second = 1;
                nums[k] = mark[i].first;
                per(nums, res, mark, k + 1);
                mark[i].second = 0;
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<pair<int, int>> mark;

        for(int i = 0; i < nums.size(); i++)
            mark.push_back({nums[i], 0});
           
        per(nums, res, mark, 0);
        return res;     
    }
};
