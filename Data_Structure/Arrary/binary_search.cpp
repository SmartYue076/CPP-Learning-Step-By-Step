#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> &nums, int target) // reference for dont copy
{
    int nums_size = nums.size(); // different from sizeof()
    int low = 0;
    int high = nums_size - 1;
    while (low <= high) // remind
    {
        int mid = low + (high - low) / 2; // prevent overflow, same as [int mid = (low + high) / 2]
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
    return -1;
}

int main()
{
    const int seq_size = 6;
    int elem_vals[] = {-1, 0, 3, 5, 9, 12};

    vector<int> nums(elem_vals, elem_vals + seq_size);
    int target = 9;

    cout << binary_search(nums, target);
}