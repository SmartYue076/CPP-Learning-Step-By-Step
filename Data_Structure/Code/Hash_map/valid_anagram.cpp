#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t)
{
    unordered_map<char, int> umap;
    for (int i = 0; i < s.size(); i++)
    {
        if (umap.find(s[i]) == umap.end())
        {
            umap[s[i]] = 0;
        }
        umap[s[i]]++;
    }

    for (int i = 0; i < t.size(); i++)
    {
        if (umap.find(t[i]) == umap.end())
            return false;
        umap[t[i]]--;
    }

    for (auto it = umap.begin(); it != umap.end(); it++)
    {
        if (it->second != 0)
            return false;
    }

    return true;

    // for (auto it = umap.begin(); it != umap.end(); it++)
    // {
    //     cout << it->first << "\t" << it->second << endl;
    // }
}

int main()
{
    bool i = isAnagram("abcda", "abcad");
    cout << i << endl;
}