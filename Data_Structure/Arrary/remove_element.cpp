#include <iostream>
#include <vector>
using namespace std;

// two pointer, change relative position
int removeElement(vector<int> &nums, int val)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        if (nums[left] == val)
        {
            nums[left] = nums[right];
            right--;
        }
        else
        {
            left++;
        }
    }
    return left;
}

// two pointer, not change relative position
// int removeElement(vector<int> &nums, int val)
// {
//     int max_index = nums.size() - 1;
//     int left = 0;
//     int right = 0;
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
    const int seq_size = 8;
    int elem_vals[] = {0, 1, 2, 2, 3, 0, 4, 2};

    vector<int> nums(elem_vals, elem_vals + seq_size);
    int target = 2;

    cout << removeElement(nums, target) << endl;
    for (int j = 0; j <= 8; j++)
    {
        cout << nums[j] << " ";
    }
    cout << endl;
}