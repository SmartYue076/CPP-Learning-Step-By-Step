#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> umap;
    for (auto i : magazine)
    {
        if (umap.find(i) == umap.end())
            umap[i] = 0;
        umap[i]++;
    }

    for (auto i : ransomNote)
    {
        if (umap.find(i) == umap.end())
            return false;
        else if (umap[i] == 0)
            return false;
        umap[i]--;
    }
    return true;
}