#include <iostream>
#include <vector>
using namespace std;

vector<int> single;
vector<vector<int>> result;
void backTracking(int n, int k, int start_index)
{
    if (single.size() == k)
    {
        result.push_back(single);
        return;
    }
    for (int i = start_index; i <= n - (k - single.size()) + 1; i++) // pruning
    {
        single.push_back(i);
        backTracking(n, k, i + 1);
        single.pop_back();
    }
    return;
}

vector<vector<int>> combine(int n, int k)
{
    backTracking(n, k, 1);
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
    vector<vector<int>> result = combine(4, 2);
    print_double_vec(result);
}