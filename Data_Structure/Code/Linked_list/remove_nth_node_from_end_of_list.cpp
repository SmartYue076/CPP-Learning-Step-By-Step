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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummynode = new ListNode(0);
        dummynode->next = head;
        ListNode *low = head;
        ListNode *high = head;
        while (n--)
        {
            high = high->next;
        }
        if (high == nullptr)
        {
            dummynode->next = head->next;
            delete head;
        }
        else{
            while (high->next != nullptr)
            {
                low = low->next;
                high = high->next;
            }
            ListNode *tmp = low->next;
            low->next = low->next->next;
            delete tmp;
        }
        ListNode *result = dummynode->next;
        delete dummynode;
        return result;
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
    test.addAtTail(head, 2);
    test.addAtTail(head, 3);
    test.printLinkedList(head);
    ListNode *new_head = test.removeNthFromEnd(head, 3);
    test.printLinkedList(new_head);
    return 0;
}