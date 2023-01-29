#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(vector<int> &nums)
{
    if (nums.size() == 1)
        return true;
    int range = 0;
    int start = 0;
    while (true)
    {
        range = max(range, start + nums[start]);
        if (range >= nums.size() - 1)
            return true;
        start++;
        if (start > range)
            return false;
    }
}

int main()
{
    vector<int> nums = {3, 2, 1, 0, 4};
    cout << canJump(nums) << endl;
    return 0;
}