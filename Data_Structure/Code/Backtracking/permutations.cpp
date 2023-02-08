#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<int> single;
vector<vector<int>> result;

void backTracking(vector<int> &nums, vector<bool> &used)
{
    if (single.size() == nums.size())
    {
        result.push_back(single);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (used[i] == true)
            continue;
        used[i] = true;
        single.push_back(nums[i]);
        backTracking(nums, used);
        single.pop_back();
        used[i] = false;
    }
    return;
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<bool> used(nums.size(), false);
    backTracking(nums, used);
    return result;
}

void print_double_vec(vector<vector<int>> &vec)
{
    for (vector<int> sub_vec : vec)
    {
        for (int ele : sub_vec)
            cout << ele << "\t";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<int> test = {1, 2, 3};
    vector<vector<int>> result = permute(test);
    print_double_vec(result);
}