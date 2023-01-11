#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
    MyQueue() {}

    void push(int x) { in_stack.push(x); }

    int pop()
    {
        if (out_stack.empty())
            update();
        int ele = out_stack.top();
        out_stack.pop();
        return ele;
    }

    int peek()
    {
        int ele = pop();
        out_stack.push(ele);
        return ele;
    }

    void update()
    {
        while (!in_stack.empty())
        {
            int ele = in_stack.top();
            in_stack.pop();
            out_stack.push(ele);
        }
    }

    bool empty()
    {
        return (in_stack.empty() && out_stack.empty());
    }

private:
    stack<int> in_stack;
    stack<int> out_stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyQueue obj = MyQueue();
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    cout << obj.pop() << endl;
    obj.push(5);
    cout << obj.pop() << endl;
    cout << obj.pop() << endl;
    cout << obj.pop() << endl;
    cout << obj.pop() << endl;
    return 0;
}