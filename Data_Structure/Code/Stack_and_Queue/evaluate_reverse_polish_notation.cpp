#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

int evalRPN(vector<string> &tokens)
{
    int result;
    stack<long long> st;
    if (tokens.size() == 1)
        return stoll(tokens[0]);
    for (string ele : tokens)
    {
        if (ele == "+" || ele == "-" || ele == "*" || ele == "/")
        {
            long long ele_right = st.top();
            st.pop();
            long long ele_left = st.top();
            st.pop();
            if (ele == "*")
                result = ele_left * ele_right;
            else if (ele == "-")
                result = ele_left - ele_right;
            else if (ele == "+")
                result = ele_left + ele_right;
            else if (ele == "/")
                result = ele_left / ele_right;
            st.push(result);
        }
        else
            st.push(stoll(ele));
    }
    return result;
}

int main()
{
    vector<string> test = {"3", "-4", "+"};
    cout << evalRPN(test) << endl;
}