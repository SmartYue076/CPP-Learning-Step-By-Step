#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i])
int minCostClimbingStairs(vector<int> &cost)
{
    if (cost.size() == 1)
        return cost[0];
    if (cost.size() == 2)
        return min(cost[0], cost[1]);
    vector<int> dp(cost.size());
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < cost.size(); i++)
        dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
    return min(dp[cost.size() - 1],dp[cost.size() - 2]);
}

int main()
{
    vector<int> test = {10,15,20};
    cout << minCostClimbingStairs(test) << endl;
    return 0;
}