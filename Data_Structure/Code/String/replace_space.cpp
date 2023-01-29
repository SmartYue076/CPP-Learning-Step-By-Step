#include <iostream>
#include <string>
using namespace std;

string replaceSpace(string s)
{
    int space_count = 0;
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        if (s[i] == ' ')
        {
            space_count++;
            s.push_back(' ');
            s.push_back(' ');
        }
    }
    int low = s.size() - 1 - space_count * 2;
    int high = s.size() - 1;
    while (high != low)
    {
        if (s[low] == ' ')
        {
            s[high--] = '0';
            s[high--] = '2';
            s[high--] = '%';
        }
        else
            s[high--] = s[low];
        low--;
        cout << low << "\t" << high << endl;
    }
    return s;
}

int main()
{
    string s = "We are happy!";
    cout << replaceSpace(s) << endl;
    return 0;
}