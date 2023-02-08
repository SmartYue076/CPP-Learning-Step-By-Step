#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int candy(vector<int> &ratings)
{
    vector<int> candy_list(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); i++)
    {
        if (ratings[i] > ratings[i - 1])
            candy_list[i] = candy_list[i - 1] + 1;
    }
    int result = candy_list[candy_list.size() - 1];
    for (int i = ratings.size() - 2; i >= 0; i--)
    {
        if ((candy_list[i] <= candy_list[i + 1]) && (ratings[i] > ratings[i + 1]))
            candy_list[i] = candy_list[i + 1] + 1;
        result += candy_list[i];
    }
    return result;
}

int main()
{
    vector<int> test = {1, 3, 4, 5, 2};
    cout << candy(test) << endl;
    return 0;
}