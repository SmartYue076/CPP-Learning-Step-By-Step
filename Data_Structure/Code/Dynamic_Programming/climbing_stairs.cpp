#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dp[i] = dp[i-1] + dp[i-2]
int climbStairs(int n)
{
    int past = 1;
    int last = 2;
    if (n == 1)
        return past;
    if (n == 2)
        return last;

    int cur = 0;
    n = n - 2;
    while (true)
    {
        cur = last + past;
        n--;
        if (n == 0)
            return cur;
        else
        {
            past = last;
            last = cur;
        }
    }
}

int main()
{
    cout << climbStairs(5) << endl;
    return 0;
}