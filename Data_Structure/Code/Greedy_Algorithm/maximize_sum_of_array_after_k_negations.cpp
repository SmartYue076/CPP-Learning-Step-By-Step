#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestSumAfterKNegations(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int min_val = INT32_MAX;
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        min_val = min(min_val, abs(nums[i]));
        if (nums[i] < 0 && k > 0)
        {
            nums[i] = -nums[i];
            k--;
        }
        result += nums[i];
    }
    if (k == 0)
        return result;
    if (k % 2 == 0)
        return result;
    else
        return result - 2 * min_val;
}

int main()
{
    vector<int> nums = {2, -3, -1, 5, -4};
    cout << largestSumAfterKNegations(nums, 2) << endl;
    return 0;
}