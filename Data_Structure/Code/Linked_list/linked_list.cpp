#include <iostream>
using namespace std;

class MyLinkedList
{
public:
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        LinkedNode(int i) : val(i), next(NULL) {}
    };
    MyLinkedList() : _dummynode(new LinkedNode(0)), _size(0) {}

    int get(int index)
    {
        if (index < 0 || index + 1 > _size)
        {
            return -1;
        }
        LinkedNode *cur = _dummynode->next;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        LinkedNode *node = new LinkedNode(val);
        node->next = _dummynode->next;
        _dummynode->next = node;
        _size++;
    }

    void addAtTail(int val)
    {
        LinkedNode *cur = _dummynode;
        while (cur->next != nullptr) // attention: not cur
        {
            cur = cur->next;
        }
        LinkedNode *node = new LinkedNode(val);
        cur->next = node;
        _size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > _size)
        {
            return;
        }
        LinkedNode *cur = _dummynode;
        while (index--)
        {
            cur = cur->next;
        }
        LinkedNode *node = new LinkedNode(val);
        node->next = cur->next;
        cur->next = node;
        _size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= _size)
        {
            return;
        }
        LinkedNode *cur = _dummynode;
        while (index--)
        {
            cur = cur->next;
        }
        LinkedNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }

    void printLinkedList()
    {
        LinkedNode *cur = _dummynode;
        while (cur->next != nullptr)
        {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    int _size;
    LinkedNode *_dummynode;
};

int main()
{
    MyLinkedList myLinkedList = MyLinkedList();
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2); // linked list becomes 1->2->3
    myLinkedList.printLinkedList();
    cout << myLinkedList.get(1) << endl; // return 2
    myLinkedList.deleteAtIndex(1);       // now the linked list is 1->3
    myLinkedList.printLinkedList();
    cout << myLinkedList.get(1) << endl; // return 3
}