#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {3, 1, 2};
    sort(nums.begin(), nums.end());
    
    do
    {
        for(auto num : nums)
            cout << num << " ";
        cout << endl;
    } while (next_permutation(nums.begin(), nums.end()));

    return 0;
}
