#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++)
    {
        int value = target - nums[i];
        if (umap.find(value) != umap.end() && umap[value] != i)
            return {umap[value], i};
        umap[nums[i]] = i;
    }
    return {};
}

int main()
{
    const int seq_size = 6;
    int elem_vals[] = {-1, 0, 3, 5, 10, 12};
    vector<int> test(elem_vals, elem_vals + seq_size);
    vector<int> result = twoSum(test, 8);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
}