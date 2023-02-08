#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool lemonadeChange(vector<int> &bills)
{
    unordered_map<int, int> umap;
    umap[5] = 0;
    umap[10] = 0;
    umap[20] = 0;

    for (int i = 0; i < bills.size(); i++)
    {
        int val = bills[i];
        if (val == 5)
            umap[5]++;
        else if (val == 10)
        {
            if (umap[5] == 0)
                return false;
            umap[5]--;
            umap[10]++;
        }
        else if (val == 20)
        {
            if (umap[10] != 0 && umap[5] != 0)
            {
                umap[10]--;
                umap[5]--;
                umap[20]++;
            }
            else if (umap[5] >= 3)
            {
                umap[5] -= 3;
                umap[20]++;
            }
            else
                return false;
        }
    }
    return true;
}

int main()
{
    vector<int> test = {5, 5, 5, 10, 20};
    cout << lemonadeChange(test) << endl;
    return 0;
}