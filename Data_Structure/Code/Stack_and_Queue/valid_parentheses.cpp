#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

bool isValid(string s)
{
    unordered_map<char, char> umap;
    umap['}'] = '{';
    umap[']'] = '[';
    umap[')'] = '(';

    stack<char> st;
    for (char ele : s)
    {
        if (ele == '{' || ele == '[' || ele == '(')
            st.push(ele);
        else if (ele == '}' || ele == ']' || ele == ')')
        {
            if (!st.empty() && (st.top() == umap[ele]))
                st.pop();
            else
                st.push(ele);
        }
    }

    return st.empty();
}

int main()
{
    cout << isValid("]") << endl;
    return 0;
}