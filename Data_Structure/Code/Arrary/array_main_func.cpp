#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> &, int);

int main()
{
    const int seq_size = 6;
    int elem_vals[] = {-1, 0, 3, 5, 9, 12};

    vector<int> nums(elem_vals, elem_vals + seq_size);
    int target = 9;

    cout << binary_search(nums, target);
}