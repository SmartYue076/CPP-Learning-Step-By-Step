// 97
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

void print_umap(unordered_map<char, int> umap)
{
    for (auto &item : umap)
    {
        cout << item.first << "\t" << item.second << endl;
    }
}

string minWindow(string s, string t)
{
    int size = s.size();
    int low = 0;
    int high = 0;
    int min_low = 0;
    int min_high = 0;
    int need_num = 0;
    int min_size = size + 1;
    unordered_map<char, int> char_num;
    unordered_map<char, int> current_num;
    for (int i = 0; i < t.size(); i++)
    {
        if (char_num[t[i]] == 0)
        {
            need_num++;
        }
        char_num[t[i]]++;
    }

    for (; high < size; high++)
    {
        if (char_num[s[high]] != 0)
        {
            current_num[s[high]]++;
            if (current_num[s[high]] == char_num[s[high]])
            {
                need_num--;
            }
        }
        while (need_num == 0)
        {
            if (char_num[s[low]] == 0)
            {
                low++;
            }
            else
            {
                if ((current_num[s[low]] - 1) >= char_num[s[low]])
                {
                    current_num[s[low]]--;
                    low++;
                }
                else
                {
                    break;
                }
            }
        }

        if (need_num == 0)
        {
            int gap = high - low + 1;
            if (gap < min_size)
            {
                min_low = low;
                min_high = high;
                min_size = gap;
            }
        }
    }
    if (need_num == 0)
    {
        return s.substr(min_low, min_high - min_low + 1);
    }
    else
    {
        return "";
    }
}

int main()
{
    string s = "AA";
    string t = "AA";
    string result = minWindow(s, t);
    cout << result << endl;
}