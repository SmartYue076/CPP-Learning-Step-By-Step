#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int nums_size = nums.size(); // different from sizeof()
    int low = 0;
    int high = nums_size - 1;
    int mid = 0;
    while (low <= high) // remind
    {
        mid = low + (high - low) / 2; // prevent overflow, same as [int mid = (low + high) / 2]
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return mid;
}

int main()
{
    const int seq_size = 6;
    int elem_vals[] = {-1, 0, 3, 5, 9, 12};

    vector<int> nums(elem_vals, elem_vals + seq_size);
    int target = 10;

    cout << searchInsert(nums, target);
}
