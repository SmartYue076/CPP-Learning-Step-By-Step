// 904. get longest sub_string which has at most two type
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int totalFruit(vector<int> &fruits)
{
    unordered_map<int, int> fruit_num;
    int left = 0;
    int right = 0;
    int type_count = 0;
    int result = 0;
    for (; right < fruits.size(); right++)
    {
        int push_type = fruits[right];
        if (fruit_num[push_type] == 0)
        {
            type_count++;
        }
        fruit_num[push_type]++;

        while (type_count > 2)
        {
            int pop_type = fruits[left];
            fruit_num[pop_type]--;
            left++;
            if (fruit_num[pop_type] == 0)
            {
                type_count--;
                break;
            }
        }
        result = result > right - left + 1 ? result : right - left + 1;
    }
    return result;
}

int main()
{
    const int seq_size = 5;
    int elem_vals[] = {1, 2, 3, 2, 2};

    vector<int> nums(elem_vals, elem_vals + seq_size);

    int result = totalFruit(nums);
    cout << result << endl;
}