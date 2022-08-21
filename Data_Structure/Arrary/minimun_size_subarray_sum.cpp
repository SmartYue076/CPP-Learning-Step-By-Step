#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// sliding window
int minSubArrayLen(int target, vector<int> &nums)
{
    int left = 0;
    int right = 0;
    int sum = nums[left]; // sum of current window
    int result = INT32_MAX;
    while (left < nums.size() and right < nums.size() and left <= right) // remind
    {
        if (sum < target)
        {
            right++;
            if (right < nums.size())
            {
                sum += nums[right];
            }
        }
        else
        {
            result = result < (right - left + 1) ? result : right - left + 1;
            if (left < nums.size())
            {
                sum -= nums[left];
            }
            left++;
        }
        // cout << "left: " << left << "     right:" << right << endl;
    }
    result = result == INT32_MAX ? 0 : result;
    return result;
}

int main()
{
    const int seq_size = 6;
    int elem_vals[] = {2, 3, 1, 2, 4, 3};

    vector<int> nums(elem_vals, elem_vals + seq_size);
    int target = 7;

    int result = minSubArrayLen(target, nums);
    cout << result << endl;
}