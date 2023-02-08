#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vec(vector<int> &);

// dp[i] = dp[i]    // recently have how many choice without current item
//       + dp[i - coins[item]]   // have how many choice with at least one current item
int change(int amount, vector<int> &coins)
{
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int item = 0; item < coins.size(); item++)
    {
        for (int i = coins[item]; i <= amount; i++)
            dp[i] += dp[i - coins[item]];
    }
    return dp[amount];
}

void print_vec(vector<int> &vec)
{
    for (int ele : vec)
        cout << ele << "\t";
    cout << endl;
}

int main()
{
    vector<int> test = {1, 2, 5};
    cout << change(5, test) << endl;
    return 0;
}