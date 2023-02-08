#include <iostream>
#include <vector>
using namespace std;

vector<string> result;
string single;
const string letterMap[10] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz", // 9
};

void backTracking(string digits, int word_index)
{
    if (single.size() == digits.size())
    {
        result.push_back(single);
        return;
    }

    int digit = digits[word_index] - '0';
    for (int i = 0; i < letterMap[digit].size(); i++)
    {
        single.push_back(letterMap[digit][i]);
        backTracking(digits, word_index + 1);
        single.pop_back();
    }
    return;
}

vector<string> letterCombinations(string digits)
{
    if (digits == "")
        return {};
    backTracking(digits, 0);
    return result;
}

void print_vec(vector<string> &vec)
{
    for (auto ele : vec)
        cout << ele << "\t";
    cout << endl;
}

int main()
{
    letterCombinations("23");
    print_vec(result);
}