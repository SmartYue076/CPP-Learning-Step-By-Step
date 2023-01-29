#include <iostream>
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

string reverseWords(string s)
{
    // reverse all
    reverse(s, 0, s.size() - 1);
    cout << "reverse all: " << s << endl;

    // remove space
    int low = 0;
    int high = 0;
    int remove_count = 0;
    while (high < s.size())
    {
        if (s[high] == '_')
        {
            if (high == 0)
            {
                while (s[high] == '_' && high < s.size())
                {
                    high++;
                    remove_count++;
                }
            }
            else if (high == (s.size() - 1))
            {
                remove_count++;
                break;
            }
            else
            {
                while (s[high] == '_' && high < s.size())
                {
                    high++;
                    remove_count++;
                }
                if (high != s.size())
                {
                    s[low] = '_';
                    low++;
                    remove_count--;
                }
            }
        }
        else
        {
            s[low] = s[high];
            high++;
            low++;
        }
    }
    s.resize(s.size() - remove_count);
    cout << "remove space: " << s << endl;

    // reverse word
    int start = -1;
    int end = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '_')
        {
            reverse(s, start, end);
            start = -1;
        }
        else if (i == s.size() - 1 && start != -1)
        {
            reverse(s, start, s.size() - 1);
        }
        else
        {
            if (start == -1)
                start = i;
            end = i;
        }
    }
    return s;
}

int main()
{
    string s = "a_good___example";
    cout << reverseWords(s) << endl;
    return 0;
}