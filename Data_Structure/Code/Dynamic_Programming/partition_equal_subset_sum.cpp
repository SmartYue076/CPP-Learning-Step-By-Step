#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vec(vector<int> &);

// dp[i] = max(dp[i], ele + dp[i - ele])
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (auto ele : nums)
        sum += ele;
    if (sum % 2 != 0)
        return false;

    int target = sum / 2;
    vector<int> dp(target + 1, 0);
    for (auto ele : nums)
    {
        for (int i = target; i >= ele; i--)
            dp[i] = max(dp[i], ele + dp[i - ele]);
    }
    // print_vec(dp);
    return dp[target] == target;
}

void print_vec(vector<int> &vec)
{
    for (int ele : vec)
        cout << ele << "\t";
    cout << endl;
}

int main()
{
    vector<int> test = {1, 5, 11, 5};
    cout << canPartition(test) << endl;
    return 0;
}