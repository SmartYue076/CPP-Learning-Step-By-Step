#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int wiggleMaxLength(vector<int> &nums)
{
    int result = 1;  // at least 1
    int prediff = 0; // insert dummy before the first same to the first val
    int curdiff = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        curdiff = nums[i + 1] - nums[i];
        if ((prediff >= 0 && curdiff < 0) || (prediff <= 0 && curdiff > 0)) // equal for flat slope
        {
            result++;
            prediff = curdiff; // ignore flat slope in single up/down
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 7, 4, 9, 2, 5};
    cout << wiggleMaxLength(nums) << endl;
    return 0;
}