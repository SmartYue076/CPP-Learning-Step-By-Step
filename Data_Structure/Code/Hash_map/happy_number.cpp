#include <iostream>
#include <unordered_set>
using namespace std;

int getSum(int n)
{
    int sum = 0;
    while (n)
    {
        sum += (n % 10) * (n % 10);
        n = n / 10;
    }
    return sum;
}

bool isHappy(int n)
{
    unordered_set<int> uset;
    int sum = n;
    while (1)
    {
        sum = getSum(sum);
        cout << sum << endl;
        if (sum == 1)
            return true;
        if (uset.find(sum) == uset.end())
        {
            uset.insert(sum);
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    bool i = isHappy(19);
    // cout << i;
}