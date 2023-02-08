#include <iostream>
#include <vector>
using namespace std;

vector<int> single;
vector<vector<int>> result;
void backTracking(int k, int n, int start_index, int sum)
{
    if (sum > n) // pruning
        return;

    if (single.size() == k)
    {
        if (sum == n)
            result.push_back(single);
        return;
    }

    for (int i = start_index; i < 9 - (k - single.size()) + 1; i++) // pruning
    {
        single.push_back(i);
        backTracking(k, n, i + 1, sum + i);
        single.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum3(int k, int n)
{
    backTracking(k, n, 1, 0);
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
    vector<vector<int>> result = combinationSum3(2, 10);
    print_double_vec(result);
}