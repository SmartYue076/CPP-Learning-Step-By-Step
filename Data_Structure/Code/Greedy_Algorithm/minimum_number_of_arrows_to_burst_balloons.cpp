#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1];
}

int findMinArrowShots(vector<vector<int>> &points)
{
    if (points.size() == 1)
        return 1;
    sort(points.begin(), points.end(), cmp);
    int pos = points[0][1];
    int count = 1;
    for (int i = 0; i < points.size() - 1; i++)
    {
        if (pos < points[i + 1][0])
        {
            count++;
            pos = points[i + 1][1];
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> test = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << findMinArrowShots(test) << endl;
    return 0;
}