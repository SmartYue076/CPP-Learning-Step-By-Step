#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    int result = 0;
    int i = 0, j = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    while (i != g.size() && j != s.size())
    {
        if (s[j] >= g[i])
        {
            i++;
            result++;
        }
        j++;
    }
    return result;
}

int main()
{
    vector<int> g = {1, 2};
    vector<int> s = {1, 2, 3};
    cout << findContentChildren(g, s) << endl;
    return 0;
}