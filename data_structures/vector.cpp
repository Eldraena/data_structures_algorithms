#include <bits/stdc++.h>
using namespace std;

int size = 10;
vector<int> nums = { 1, -45, 54, -71, 76, 12 };
vector<int> vt1(size, 0);

sort(block_and_sheet.begin(), block_and_sheet.end(), [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b)
{
    if(a.second.second != b.second.second)
        return a.second.second < b. second.second;
    else
        return a.first < b.first;
});
 
int main()
{
    
    int max_num = *max_element(nums.begin(),nums.end());
    int min_num = *min_element(nums.begin(),nums.end());
    int sum = accumulate(nums.begin(), nums.end(), 0);
 
    cout << "Max Element = " << max_num << endl;
    cout << "Min Element = " << min_num << endl;
    cout << "Sum = " << sum << endl;

    vector
    return 0;
}
