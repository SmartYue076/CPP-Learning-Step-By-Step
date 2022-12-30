#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int count = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        if (nums[i] == val)
        {
            ++count;
        }
        else
        {
            nums[i - count] = nums[i];
        }
    }
    return size - count;
}

// // two pointer, not change relative position
// int removeElement(vector<int> &nums, int val)
// {
//     int max_index = nums.size() - 1;
//     int left = 0; // find index need update(may update not need element)
//     int right = 0; //prepare to overwrite
//     for (; right <= max_index; right++)
//     {
//         if (nums[right] != val)
//         {
//             nums[left] = nums[right];
//             left++;
//         }
//     }
//     return left;
// }

// // two pointer, change relative position
// int removeElement(vector<int> &nums, int val)
// {
//     int left = 0;
//     int right = nums.size() - 1;
//     while (left <= right)
//     {
//         if (nums[left] == val)
//         {
//             nums[left] = nums[right];
//             right--;
//         }
//         else
//         {
//             left++;
//         }
//     }
//     return left;
// }

// two for, O(n^2)
//  int removeElement(vector<int> &nums, int val)
//  {
//      int max_index = nums.size() - 1;
//      for (int i = max_index; i >= 0; i--)
//      {
//          if (nums[i] == val)
//          {
//              for (int update_index = i; update_index < max_index; update_index++)
//              {
//                  nums[update_index] = nums[update_index + 1];
//              }
//              max_index--;
//          }
//      }
//      return max_index + 1;
//  }

int main()
{
    const int seq_size = 4;
    int elem_vals[] = {3, 2, 2, 3};

    vector<int> nums(elem_vals, elem_vals + seq_size);
    int target = 3;

    cout << removeElement(nums, target) << endl;
    for (int j = 0; j <= seq_size - 1; j++)
    {
        cout << nums[j] << " ";
    }
    cout << endl;
}