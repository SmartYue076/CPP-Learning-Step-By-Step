#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dp[i] = dp[i-1] + dp[i-2]
int fib(int n)
{
    int past = 0;
    int last = 1;
    if (n == 0)
        return past;
    if (n == 1)
        return last;

    int cur = 0;
    n = n - 1;
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
    cout << fib(5) << endl;
    return 0;
}