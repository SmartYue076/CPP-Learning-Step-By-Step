#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_double_vec(vector<vector<int>> &);

// dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1)
        return 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (i == 1 && j == 1)
                dp[i][j] = 1;
            else if (obstacleGrid[i - 1][j - 1] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m][n];
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
    vector<vector<int>> test = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << uniquePathsWithObstacles(test) << endl;
    return 0;
}