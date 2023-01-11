#include <iostream>
#include <stack>
using namespace std;

string removeDuplicates(string s)
{
    string result;
    stack<char> st;
    for (char ele : s)
    {
        if (!st.empty() && st.top() == ele)
            st.pop();
        else
            st.push(ele);
    }

    while (!st.empty())
    {
        auto it = result.begin();
        result.insert(it, st.top());
        st.pop();
    }
    return result;
}

int main()
{
    cout<<removeDuplicates("abbaca");
}