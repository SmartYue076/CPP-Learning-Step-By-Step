#include <iostream>
#include <queue>
using namespace std;

// fun1: use one queue
class MyStack
{
public:
    MyStack() {}

    void push(int x) { main_queue.push(x); }

    int pop()
    {
        int result;
        int size = main_queue.size();
        while (size)
        {
            int ele = main_queue.front();
            main_queue.pop();
            size--;
            if (!size)
                result = ele;
            else
                main_queue.push(ele);
        }
        return result;
    }

    int top()
    {
        int ele = pop();
        main_queue.push(ele);
        return ele;
    }

    bool empty() { return main_queue.empty(); }

private:
    queue<int> main_queue;
};
// // fun2: use two queue
// class MyStack
// {
// public:
//     MyStack() {}

//     void push(int x) { main_queue.push(x); }

//     int pop()
//     {
//         int result;
//         while (1)
//         {
//             int ele = main_queue.front();
//             main_queue.pop();
//             if (main_queue.empty())
//             {
//                 result = ele;
//                 break;
//             }
//             else
//             {
//                 bk_queue.push(ele);
//             }
//         }

//         while (!bk_queue.empty())
//         {
//             int ele = bk_queue.front();
//             bk_queue.pop();
//             main_queue.push(ele);
//         }
//         return result;
//     }

//     int top()
//     {
//         int ele = pop();
//         push(ele);
//         return ele;
//     }

//     bool empty() { return main_queue.empty(); }

// private:
//     queue<int> main_queue;
//     queue<int> bk_queue;
// };

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyStack obj = MyStack();
    obj.push(1);
    obj.push(2);
    cout << obj.top() << endl;
    cout << obj.pop() << endl;
    cout << obj.empty() << endl;
    return 0;
}