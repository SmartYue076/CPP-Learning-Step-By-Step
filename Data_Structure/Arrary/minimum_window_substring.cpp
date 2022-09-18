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
    unordered_map<char, int> window_freq;
    unordered_map<char, int> freq;
    int left = 0;
    int right = 0;
    int valid_count = 0;
    int need_count = 0;
    int min_size = INT32_MAX;
    int result_left = -1;
    int result_right = -1;

    for (int i = 0; i < t.size(); i++)
    {
        if (freq[t[i]] == 0)
        {
            need_count++;
        }
        freq[t[i]]++;
    }

    while (right < s.size() and left <= right)
    {
        window_freq[s[right]]++;
        if (window_freq[s[right]] == freq[s[right]])
        {
            valid_count++;
        }

        if (valid_count == need_count)
        {
            while (valid_count == need_count)
            {
                window_freq[s[left]]--;
                if (window_freq[s[left]] < freq[s[left]])
                {
                    valid_count--;
                }
                left++;
            }

            int window_size = right - (left - 1) + 1;
            if (window_size < min_size)
            {
                result_right = right;
                result_left = left - 1;
                min_size = window_size;
            }
        }
        right++;
    }

    if (result_left == -1 and result_right == -1)
    {
        return "";
    }
    else
    {
        return s.substr(result_left, result_right - result_left + 1);
    }
}

int main()
{
    string s = "AA";
    string t = "AA";
    string result = minWindow(s, t);
    cout << result << endl;
}