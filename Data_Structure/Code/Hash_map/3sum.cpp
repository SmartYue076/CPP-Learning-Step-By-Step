#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int low = i + 1;
        int high = nums.size() - 1;
        while (low < high)
        {
            if (nums[low] + nums[high] == -nums[i])
            {
                result.push_back({nums[i], nums[low], nums[high]});
                while (low < high && nums[low] == nums[low + 1])
                    low++;
                while (low < high && nums[high] == nums[high - 1])
                    high--;
                low++;
                high--;
            }
            else if (nums[low] + nums[high] > -nums[i])
                high--;
            else
                low++;
        }
    }
    return result;
}

void print(vector<vector<int>> n)
{
    for (int i = 0; i < n.size(); i++)
    {
        for (int j = 0; j < n[i].size(); j++)
            cout << n[i][j] << "\t";
        cout << endl;
    }
}

int main()
{
    vector<int> input = {-4, -1, -1, 0, 1, 2};
    vector<vector<int>> result = threeSum(input);
    print(result);
}