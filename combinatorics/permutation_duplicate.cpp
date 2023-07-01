class Solution {
public:

    void per(vector<int>& nums, vector<vector<int>>& res, vector<pair<int, int>> &hash, int k)
    {
        if(k == nums.size())
        {
            res.push_back(nums);
            return;
        }

        for(int i = 0; i < hash.size(); i++)
        {
            if(hash[i].second > 0)
            {
                hash[i].second--;
                nums[k] = hash[i].first;
                per(nums, res, hash, k + 1);
                hash[i].second++;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<pair<int, int>> hash;

        for(int i = 0; i < nums.size(); i++)
        {
            bool isExist = false;
            for(int j = 0; j < hash.size(); j++)
            {
                if(hash[j].first == nums[i])
                {
                    hash[j].second++;
                    isExist = true;
                    break;
                }                     
            }

            if(!isExist)
            {
                hash.push_back({nums[i], 1});
            }         
        }
                     
        per(nums, res, hash, 0);
        return res;  
    }
};
