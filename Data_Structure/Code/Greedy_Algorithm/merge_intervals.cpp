#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_double_vec(vector<vector<int>> &);

static bool cmp(const vector<int> &a, const vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    else
        return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.size() == 1)
        return intervals;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    int start = intervals[0][0];
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++)
    {
        if (end >= intervals[i][0])
            end = max(end, intervals[i][1]);
        else
        {
            result.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }
    result.push_back({start, end});
    return result;
}

void print_double_vec(vector<vector<int>> &vec)
{
    for (vector<int> sub_vec : vec)
    {
        for (int ele : sub_vec)
            cout << ele << "\t";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> test = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = merge(test);
    print_double_vec(result);
    return 0;
}