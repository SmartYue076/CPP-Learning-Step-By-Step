#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int result = INT32_MIN;
    int sub_sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sub_sum += nums[i];
        if (sub_sum > result)
            result = sub_sum;
        if (sub_sum < 0)
            sub_sum = 0;
    }
    return result;
}

int main()
{
    vector<int> nums = {8, -19, 5, -4, 20};
    cout << maxSubArray(nums) << endl;
    return 0;
}