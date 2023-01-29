#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int result = 0;
    for (int i = 0; i < prices.size() - 1; i++)
    {
        int diff = prices[i + 1] - prices[i];
        if (diff > 0)
            result += diff;
    }
    return result;
}

int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(nums) << endl;
    return 0;
}