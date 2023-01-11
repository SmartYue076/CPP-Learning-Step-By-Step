#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    int count = 0;
    unordered_map<int, int> umap;
    for (auto a : nums1)
        for (auto b : nums2)
            umap[a + b]++;

    for (auto a : nums3)
        for (auto b : nums4)
        {
            if (umap.find(-(a + b)) != umap.end())
                count += umap[-(a + b)];
        }
    return count;
}