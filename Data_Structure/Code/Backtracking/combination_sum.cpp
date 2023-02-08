#include <iostream>
#include <vector>
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
        single.push_back(candidates[i]);
        backTracking(candidates, target, i, sum + candidates[i]);
        single.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
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
    vector<int> test = {2, 3, 6, 7};
    vector<vector<int>> result = combinationSum(test, 7);
    print_double_vec(result);
}