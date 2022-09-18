// 34. Find First and Last Position of Element in Sorted Array
// Given an array of integers nums sorted in non-decreasing order,
// find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

#include <iostream>
#include <vector>
using namespace std;

int searchLow(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    int board = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // intend to find left
        if (nums[mid] >= target)
        {
            high = mid - 1;
            if (nums[mid] == target)
            {
                board = mid;
            }
        }
        else
        {
            low = mid + 1;
        }
    }
    return board;
}

int searchHigh(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    int board = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // intend to find right
        if (nums[mid] <= target)
        {
            low = mid + 1;
            if (nums[mid] == target)
            {
                board = mid;
            }
        }
        else
        {
            high = mid - 1;
        }
    }
    return board;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    return {searchLow(nums, target), searchHigh(nums, target)};
}

int main()
{
    const int seq_size = 7;
    int elem_vals[] = {-1, 0, 3, 5, 5, 9, 12};

    vector<int> nums(elem_vals, elem_vals + seq_size);
    int target = 5;

    cout << searchLow(nums, target) << endl;
    cout << searchHigh(nums, target) << endl;
}