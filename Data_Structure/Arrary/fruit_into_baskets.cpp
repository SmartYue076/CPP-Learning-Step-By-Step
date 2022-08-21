#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int get_value_in_vec(vector<int> &vec, int target)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int totalFruit(vector<int> &fruits)
{
    int first_type = -1;
    int second_type = -1;
    int result = INT32_MAX;
    int left = 0;
    int right = 0;
    vector<int> type;
    while (right < fruits.size())
    {
        if (get_value_in_vec(type, fruits[right]) == -1)
        {
            if (type.size() == 2)
            {
                type.erase(type.begin());
            }
            type.push_back(fruits[right]);
        }
        result = min(result, right - left + 1);
        right++;
    }
}

// int main()
// {
//     const int seq_size = 6;
//     int elem_vals[] = {2, 3, 1, 2, 4, 3};

//     vector<int> nums(elem_vals, elem_vals + seq_size);
//     int target = 7;

//     int result = minSubArrayLen(target, nums);
//     cout << result << endl;
// }