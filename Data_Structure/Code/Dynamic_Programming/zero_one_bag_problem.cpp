#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vec(vector<int> &);
void print_double_vec(vector<vector<int>> &);

// dp[i] = max(
//                dp[i - 1][j],   // dont get
//                value[i] + dp[i - 1][j - weight[i]] // get
//            )
int bagProcess(int capacity, vector<int> weight, vector<int> value)
{
    if ((weight.size() != value.size()) || (weight.size() == 0))
        return -1;
    int size = weight.size();
    vector<vector<int>> dp(size, vector<int>(capacity + 1, 0));
    // inital
    for (int i = weight[0]; i <= capacity; i++)
        dp[0][i] = value[0];

    // dp
    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (weight[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], value[i] + dp[i - 1][j - weight[i]]);
        }
    }
    // print_double_vec(dp);
    return dp[size - 1][capacity];
}

// dp[i] = max(
//                dp[i][j],   // dont get
//                value[i] + dp[j - weight[i]] // get
//            )
int bagProcessWithOneVector(int capacity, vector<int> weight, vector<int> value)
{
    if ((weight.size() != value.size()) || (weight.size() == 0))
        return -1;
    int size = weight.size();
    vector<int> dp(capacity + 1, 0);

    // dp
    for (int item = 0; item < size; item++)
    {
        for (int i = capacity; i >= weight[item]; i--)
            dp[i] = max(dp[i], value[item] + dp[i - weight[item]]);
    }
    // print_vec(dp);
    return dp[capacity];
}

void print_vec(vector<int> &vec)
{
    for (int ele : vec)
        cout << ele << "\t";
    cout << endl;
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
    vector<int> weight = {4, 3, 1}; // at any order
    vector<int> value = {30, 20, 15};
    cout << bagProcessWithOneVector(4, weight, value) << endl;
    return 0;
}