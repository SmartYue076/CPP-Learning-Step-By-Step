#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> single;
vector<vector<int>> result;

void backTracking(vector<int> &candidates, int target, int start_index, int sum)
{
    if (sum == target)
    {
        result.push_back(single);
        return;
    }

    for (int i = start_index; i < candidates.size() && sum + candidates[i] <= target; i++)
    {
        if (i > start_index && candidates[i] == candidates[i - 1])
            continue;
        single.push_back(candidates[i]);
        backTracking(candidates, target, i + 1, sum + candidates[i]);
        single.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    backTracking(candidates, target, 0, 0);
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
    vector<int> test = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> result = combinationSum2(test, 8);
    print_double_vec(result);
}