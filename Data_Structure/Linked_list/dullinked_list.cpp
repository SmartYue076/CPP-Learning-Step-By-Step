#include <iostream>
using namespace std;

class MyLinkedList
{
public:
    struct DulLinkedNode
    {
        int val;
        DulLinkedNode *prev;
        DulLinkedNode *next;
        DulLinkedNode(int i) : val(i), prev(NULL), next(NULL) {}
    };

    MyLinkedList() : _dummynode(new DulLinkedNode(0)), _size(0) {}

    int get(int index)
    {
        if (index < 0 || index + 1 > _size)
        {
            return -1;
        }
        DulLinkedNode *cur = _dummynode->next;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        DulLinkedNode *node = new DulLinkedNode(val);
        node->next = _dummynode->next;
        _dummynode->next = node;
        node->prev = _dummynode;
        _size++;
    }

    void addAtTail(int val)
    {
        DulLinkedNode *cur = _dummynode;
        while (cur->next != nullptr) // attention: not cur
        {
            cur = cur->next;
        }
        DulLinkedNode *node = new DulLinkedNode(val);
        cur->next = node;
        node->prev = cur;
        _size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > _size)
        {
            return;
        }
        DulLinkedNode *cur = _dummynode;
        while (index--)
        {
            cur = cur->next;
        }
        DulLinkedNode *node = new DulLinkedNode(val);
        node->next = cur->next;
        cur->next = node;
        node->prev = cur;
        _size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= _size)
        {
            return;
        }
        DulLinkedNode *cur = _dummynode;
        while (index--)
        {
            cur = cur->next;
        }
        DulLinkedNode *tmp = cur->next;
        cur->next = cur->next->next;
        if (cur->next != nullptr)
        {
            cur->next->prev = cur;
        }
        delete tmp;
        _size--;
    }

    void printLinkedList()
    {
        DulLinkedNode *cur = _dummynode;
        while (cur->next != nullptr)
        {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    int _size;
    DulLinkedNode *_dummynode;
};

int main()
{
    MyLinkedList myLinkedList = MyLinkedList();
    // myLinkedList.addAtHead(1);
    // myLinkedList.addAtTail(3);
    // myLinkedList.addAtIndex(1, 2); // linked list becomes 1->2->3
    // myLinkedList.printLinkedList();
    // cout << myLinkedList.get(1) << endl; // return 2
    // myLinkedList.deleteAtIndex(1);       // now the linked list is 1->3
    // myLinkedList.printLinkedList();
    // cout << myLinkedList.get(1) << endl; // return 3
    myLinkedList.addAtHead(1);
    myLinkedList.printLinkedList();
    myLinkedList.deleteAtIndex(0);
    myLinkedList.printLinkedList();
}