#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int jump(vector<int> &nums)
{
    if (nums.size() == 1)
        return 0;
    int cur_index = 0;
    int cut_index = nums[0];
    int range = 0;
    int count = 1;
    while (true)
    {
        range = max(range, cur_index + nums[cur_index]);
        if (cur_index == cut_index)
        {
            count++;
            cut_index = range;
        }
        if (cut_index >= nums.size() - 1)
            return count;
        cur_index++;
    }
    return count;
}

int main()
{
    vector<int> nums = {2, 3, 0, 1, 4};
    cout << jump(nums) << endl;
    return 0;
}