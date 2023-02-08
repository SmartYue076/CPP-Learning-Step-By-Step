#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (i == 1 && j == 1)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m][n];
}

int main()
{
    cout << uniquePaths(3, 7) << endl;
    return 0;
}