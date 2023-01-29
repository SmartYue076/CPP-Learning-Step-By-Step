#include <iostream>
#include <vector>
#include <string>
using namespace std;

inline void reverse(string &s, int low, int high)
{
    while (low < high)
    {
        swap(s[low], s[high]);
        low++;
        high--;
    }
    return;
}

string reverseStr(string s, int k)
{
    for (int i = 0; i < s.size(); i += (2 * k))
    {
        if (i + k <= s.size())
        {
            reverse(s, i, i + k - 1);
            continue;
        }
        reverse(s, i, s.size() - 1);
    }
    return s;
}

int main()
{
    string s = "abcd";
    cout << reverseStr(s, 2) << endl;
    return 0;
}