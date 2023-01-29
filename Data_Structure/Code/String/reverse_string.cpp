#include <vector>
using namespace std;

void reverseString(vector<char> &s)
{
    int size = s.size();
    int low = 0;
    int high = size - 1;
    while (low < high)
    {
        swap(s[low], s[high]);
        low++;
        high--;
    }
    return;
}