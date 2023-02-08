#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void print_vec(vector<int> &);

vector<int> partitionLabels(string s)
{
    int last[27] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        last[s[i] - 'a'] = i;
    }
    vector<int> result;
    int left = 0;
    int right = 0;
    for (int i = 0; i < s.size(); i++)
    {
        right = max(right, last[s[i] - 'a']);
        if (i == right)
        {
            result.push_back(right - left + 1);
            left = i + 1;
        }
    }
    return result;
}

void print_vec(vector<int> &vec)
{
    for (int ele : vec)
        cout << ele << "\t";
    cout << endl;
}

int main()
{
    string s = "ababcbacadefegdehijhklij";
    vector<int> result = partitionLabels(s);
    print_vec(result);
    return 0;
}