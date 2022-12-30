#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *tmp;
        ListNode *pre = NULL;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    // ListNode *reverse(ListNode *pre, ListNode *cur)
    // {
    //     if (cur == nullptr)
    //     {
    //         return pre;
    //     }
    //     ListNode *tmp = cur->next;
    //     cur->next = pre;
    //     return reverse(cur, tmp);
    // }

    // ListNode *reverseList(ListNode *head)
    // {
    //     return reverse(NULL,head);
    // }

    void printLinkedList(ListNode *head)
    {
        ListNode *cur = head;
        while (cur != nullptr)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void addAtTail(ListNode *head, int val)
    {
        ListNode *cur = head;
        if (cur == nullptr)
        {
            cur = new ListNode(val);
            return;
        }
        while (cur->next != nullptr) // attention: not cur
        {
            cur = cur->next;
        }
        ListNode *node = new ListNode(val);
        cur->next = node;
    }
};

int main()
{
    Solution test = Solution();
    ListNode *head = new ListNode(1);
    test.addAtTail(head, 2);
    test.addAtTail(head, 3);
    test.printLinkedList(head);
    ListNode *new_head = test.reverseList(head);
    test.printLinkedList(new_head);
    return 0;
}