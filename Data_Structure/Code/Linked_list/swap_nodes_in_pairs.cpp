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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        ListNode *cur = head->next;
        ListNode *new_head;
        if (cur == nullptr)
        {
            return head;
        }
        else
        {
            new_head = cur;
        }

        ListNode *pre = head;
        while (cur != nullptr)
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre->next = tmp;
            ListNode *pre_tmp = pre;
            pre = tmp;
            if (pre != nullptr)
            {
                cur = pre->next;
                if (cur!= nullptr)
                {
                    pre_tmp->next = cur;
                }
            }
            else
            {
                cur = nullptr;
            }
        }
        return new_head;
    }

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
    // test.addAtTail(head, 2);
    // test.addAtTail(head, 3);
    // test.addAtTail(head, 4);
    test.printLinkedList(head);
    ListNode *new_head = test.swapPairs(head);
    test.printLinkedList(new_head);
    return 0;
}