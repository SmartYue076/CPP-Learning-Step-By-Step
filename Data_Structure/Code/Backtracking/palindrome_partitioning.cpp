#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> single;
vector<vector<string>> result;

bool isPartition(string s)
{
    int low = 0;
    int high = s.size() - 1;
    while (low < high)
    {
        if (s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}

void backTracking(string s, int start_index)
{
    if (start_index == s.size())
    {
        result.push_back(single);
        return;
    }

    for (int i = start_index; i < s.size(); i++)
    {
        string sub_str = s.substr(start_index, i - start_index + 1);
        if (!isPartition(sub_str))
            continue;
        single.push_back(sub_str);
        backTracking(s, i + 1);
        single.pop_back();
    }
}

vector<vector<string>> partition(string s)
{
    backTracking(s, 0);
    return result;
}

void print_double_vec(vector<vector<string>> &vec)
{
    for (vector<string> sub_vec : vec)
    {
        for (auto ele : sub_vec)
            cout << ele << "\t";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    string test = "aab";
    vector<vector<string>> result = partition(test);
    print_double_vec(result);
}