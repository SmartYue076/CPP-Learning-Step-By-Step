#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<int> single;
vector<vector<int>> result;

void backTracking(vector<int> &nums, int start_index)
{
    if (single.size() >= 2)
        result.push_back(single);
    if (start_index == nums.size())
        return;

    unordered_set<int> uset;
    for (int i = start_index; i < nums.size(); i++)
    {
        if (single.size() >= 1 && nums[i] < single[single.size() - 1])
            continue;
        if (uset.find(nums[i]) != uset.end())
            continue;
        single.push_back(nums[i]);
        backTracking(nums, i + 1);
        single.pop_back();
        uset.insert(nums[i]);
    }
    return;
}

vector<vector<int>> findSubsequences(vector<int> &nums)
{
    backTracking(nums, 0);
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
    vector<int> test = {4, 7, 6, 7};
    vector<vector<int>> result = findSubsequences(test);
    print_double_vec(result);
}