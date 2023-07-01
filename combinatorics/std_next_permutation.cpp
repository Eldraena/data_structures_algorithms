class Solution 
{
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>>results;
        sort(nums.begin(), nums.end());
        results.push_back(nums);

        while(next_permutation(nums.begin(), nums.end()))
        {
            results.push_back(nums);
        }
        return results;
    }
};
