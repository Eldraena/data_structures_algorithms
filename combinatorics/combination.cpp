class Solution {
public:
    void comb(vector<int>& data, vector<vector<int>>& res, vector<int> nums, int k, int id)
    {
        if(id == k)
        {
            res.push_back(data);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(id == 0 || (id > 0 && nums[i] > data[id - 1]))
            {
                data[id] = nums[i];
                comb(data, res, nums, k, id + 1);
            }
        }
    }

    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> res;
        vector<int> nums, data;

        for(int i = 1; i <= n; i++)
            nums.push_back(i);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < k; i++)
            data.push_back(0);

        comb(data, res, nums, k, 0);
        return res;  
    }
};
