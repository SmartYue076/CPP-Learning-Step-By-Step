#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int result = -1;
    int sum = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        int diff = gas[i] - cost[i];
        if (diff >= 0 && result == -1)
            result = i;
        if (result != -1)
            sum += diff;
        if (sum < 0)
        {
            result = -1;
            sum = 0;
        }
    }
    if (result == -1)
        return -1;

    for (int i = 0; i < result; i++)
    {
        int diff = gas[i] - cost[i];
        sum += diff;
        if (sum < 0)
            return -1;
    }
    return result;
}

int main()
{
    vector<int> gas = {2, 3, 4};
    vector<int> cost = {3, 4, 3};
    cout << canCompleteCircuit(gas, cost) << endl;
    return 0;
}