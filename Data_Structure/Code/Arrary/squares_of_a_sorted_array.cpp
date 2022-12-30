#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    vector<int> result(nums.size(), 0);
    int left = 0;
    int right = nums.size() - 1;
    int result_index = nums.size() - 1;
    while (left <= right)
    {
        if (nums[left] * nums[left] <= nums[right] * nums[right])
        {
            result[result_index] = nums[right] * nums[right];
            right--;
        }
        else
        {
            result[result_index] = nums[left] * nums[left];
            left++;
        }
        result_index--;
    }
    return result;
}

int main()
{
    const int seq_size = 5;
    int elem_vals[] = {-7, -3, 2, 3, 11};

    vector<int> nums(elem_vals, elem_vals + seq_size);
    int target = 2;

    vector<int> result = sortedSquares(nums);
    for (int j = 0; j < 5; j++)
    {
        cout << result[j] << " ";
    }
    cout << endl;
}