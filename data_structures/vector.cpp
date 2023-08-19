#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    vector<int> nums = { 1, -45, 54, -71, 76, 12 };
    int max_num = *max_element(nums.begin(),nums.end());
    int min_num = *min_element(nums.begin(),nums.end());
    int sum = accumulate(nums.begin(), nums.end(), 0);
 
    cout << "Max Element = " << max_num << endl;
    cout << "Min Element = " << min_num << endl;
    cout << "Sum = " << sum << endl;
    return 0;
}
