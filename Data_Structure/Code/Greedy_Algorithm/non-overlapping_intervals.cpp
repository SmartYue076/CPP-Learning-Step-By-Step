#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vec(vector<int> &);

static bool cmp(const vector<int> &a, const vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    else
        return a[0] < b[0];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    if (intervals.size() == 1)
        return 0;
    sort(intervals.begin(), intervals.end(), cmp);
    int count = 0;
    vector<int> base = intervals[0];
    for (int i = 0; i < intervals.size() - 1; i++)
    {
        if (intervals[i + 1][0] < base[1])
        {
            count++;
            if ((base[0] != intervals[i + 1][0]) && (base[1] > intervals[i + 1][1]))
                base = intervals[i + 1];
        }
        else
            base = intervals[i + 1];
    }
    return count;
}

void print_vec(vector<int> &vec)
{
    for (int ele : vec)
        cout << ele << "\t";
    cout << endl;
}

int main()
{
    vector<vector<int>> test = {{0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6}};
    cout << eraseOverlapIntervals(test) << endl;
    return 0;
}