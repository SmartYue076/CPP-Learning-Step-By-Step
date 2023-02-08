#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vec(vector<int> &);

// j = 1 : i - 1
// dp[i] = max(dp[i], j * (i - j), j * dp[i - j])
int integerBreak(int n)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 2; i <= n; i++) // for dp
    {
        for (int j = 1; j < i; j++)
        {
            int max_val = max(j * (i - j), j * dp[i - j]);
            dp[i] = max(dp[i], max_val);
        }
    }
    return dp[n];
}

void print_vec(vector<int> &vec)
{
    for (int ele : vec)
        cout << ele << "\t";
    cout << endl;
}

int main()
{
    cout << integerBreak(10) << endl;
    return 0;
}