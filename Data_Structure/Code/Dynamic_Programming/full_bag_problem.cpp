#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vec(vector<int> &);

// dp[i] = max(
//                dp[i][j],   // dont get
//                value[i] + dp[j - weight[i]] // get
//            )
int bagProcessWithOneVector(int capacity, vector<int> weight, vector<int> value)
{
    if ((weight.size() != value.size()) || (weight.size() == 0))
        return -1;
    vector<int> dp(capacity + 1, 0);
    for (int item = 0; item < weight.size(); item++)
    {
        for (int i = weight[item]; i <= capacity; i++)
            dp[i] = max(dp[i], value[item] + dp[i - weight[item]]);
    }
    return dp[capacity];
}

void print_vec(vector<int> &vec)
{
    for (int ele : vec)
        cout << ele << "\t";
    cout << endl;
}

int main()
{
    vector<int> weight = {4, 3, 1}; // at any order
    vector<int> value = {30, 20, 15};
    cout << bagProcessWithOneVector(4, weight, value) << endl;
    return 0;
}