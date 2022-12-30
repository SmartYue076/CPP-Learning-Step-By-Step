#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

void print_vec(vector<vector<int> > result, int target)
{
    for (int i = 0; i < target; i++)
    {
        for (int j = 0; j < target; j++)
        {
            cout << result[i][j] << " ";
        }
    }
    cout << endl;
}
vector<vector<int> > generateMatrix(int n)
{
    vector<vector<int> > result(n, vector<int>(n, 0));
    int num = 0;
    int start = 0;
    int end = n - 1;
    while (num <= n * n)
    {
        for (int j = 0; j < n; j++)
        {
            if (result[start][j] == 0)
            {
                num++;
                result[start][j] = num;
                if (num == n * n)
                    return result;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (result[i][end] == 0)
            {
                num++;
                result[i][end] = num;
                if (num == n * n)
                    return result;
            }
        }

        for (int j = n - 1; j >= 0; j--)
        {
            if (result[end][j] == 0)
            {
                num++;
                result[end][j] = num;
                if (num == n * n)
                    return result;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (result[i][start] == 0)
            {
                num++;
                result[i][start] = num;
                if (num == n * n)
                    return result;
            }
        }
        start++;
        end--;
    }
    return result;
}

int main()
{
    // const int seq_size = 11;
    // int elem_vals[] = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};

    // vector<int> nums(elem_vals, elem_vals + seq_size);
    int target = 3;
    vector<vector<int> > result = generateMatrix(target);
    cout << "---" << endl;
    print_vec(result, target);
    cout << endl;
}