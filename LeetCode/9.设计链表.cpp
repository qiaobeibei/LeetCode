/*
你可以选择使用单链表或者双链表，设计并实现自己的链表。

单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。

如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

实现 MyLinkedList 类：

MyLinkedList() 初始化 MyLinkedList 对象。
int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
*/
#include<iostream>

class MyLinkedList {
public:
    MyLinkedList() {
        _dummyHead = new ListNode(0);
        _size = 0;
    }
    ~MyLinkedList() {  }
    int get(int index);
    void addAtHead(int val);
    void addAtTail(int val);
    void addAtIndex(int index, int val);
    void deleteAtIndex(int index);
    void printLinkedList();

private:
    struct ListNode {
        int val;
        ListNode* next;
        explicit ListNode(int x) : val(x), next(nullptr) {}
        ListNode() :val(0), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };
    ListNode* _dummyHead;
    int _size;
};

// 获取链表中第 index 个节点的值。如果索引无效，则返回-1
int MyLinkedList::get(int index) {
    if (index < 0 or index > _size - 1) return - 1;
    auto cur = _dummyHead;
    int len = 0;
    while (cur->next != nullptr) {
        if (len == index)
            return cur->next->val;
        else {
            len++;
            cur = cur->next;
        }
    }
    return -1;
}
// 在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点
void MyLinkedList::addAtHead(int val) {
    auto head = new ListNode(val);
    head->next = _dummyHead->next;
    _dummyHead->next = head;
    _size++;
}
// 将值为 val 的节点追加到链表的最后一个元素
void MyLinkedList::addAtTail(int val) {
    auto cur = _dummyHead;
    while (cur->next != nullptr) 
        cur = cur->next;
    cur->next = new ListNode(val);
    _size++;
}
// 在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点
// 将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点
void MyLinkedList::addAtIndex(int index, int val) {
    auto cur = _dummyHead;
    int len = 0;

    if (index < 0) addAtHead(val);
    else if (index == _size) addAtTail(val);
    else if (index > _size) return;
    else {
        while (cur->next != nullptr) {
            if (len == index) {
                auto newNode = new ListNode(val);
                newNode->next = cur->next;
                cur->next = newNode;
                _size++;
                break;
            }
            else {
                len++;
                cur = cur->next;
            }
        }
    }
}
// 如果索引 index 有效，则删除链表中的第 index 个节点
void MyLinkedList::deleteAtIndex(int index) {
    if (index< 0 || index > _size - 1) return;//index值无效，直接返回
    auto cur = _dummyHead;
    int len = 0;

    while (cur->next != nullptr) {
        if (len == index) {
            cur->next = cur->next->next;
            _size--;
            break;
        }
        else {
            len++;
            cur = cur->next;
        }
    }
}

// 打印链表
void MyLinkedList::printLinkedList() {
    ListNode* cur = _dummyHead;
    //std::cout << "size is " << _size << std::endl;
    while (cur->next != nullptr) {
        std::cout << cur->next->val << "->";
        cur = cur->next;
    }
    // std::cout << _dummyHead->next->val << std::endl;
    std::cout << std::endl;
}

class MyLinkedList2 {
public:
    MyLinkedList2() {
        _dummyHead = new ListNode(0);
        _size = 0;
    }
    ~MyLinkedList2() {  }
    
    int get(int index) {// 获取链表中第index个节点的值
        if (index <0 or index > _size - 1) return -1;
        auto head = _dummyHead->next;
        while (index--) head = head->next;
        return head->val;
    }
    void addAtHead(int val) {// 在链表的第一个元素之前添加一个值为val的节点
        auto newNode = new ListNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    void addAtTail(int val) {// 将值为val的节点追加到链表的最后一个元素
        auto cur = _dummyHead;
        while (cur->next != nullptr) cur = cur->next;
        cur->next = new ListNode(val);
        _size++;
    }

    void addAtIndex(int index, int val) {//在链表的第一个元素之前添加一个值为val的节点
        auto cur = _dummyHead;
        auto newNode = new ListNode(val);

        if (index <= 0)  addAtHead(val);
        else if (index == _size) addAtTail(val);
        else if (index > _size) return;
        else {
            while (index--) cur = cur->next;
            newNode->next = cur->next;
            cur->next = newNode;
            _size++;
        }
    }
    void deleteAtIndex(int index) {// 删除链表中的第index个节点
        if (index<0 || index>_size - 1) return;//index值无效，直接返回
        ListNode* cur = _dummyHead, * t = nullptr;
        while (index--) cur = cur->next;   // 找到第index-1个结点
        t = cur->next;
        cur->next = t->next;
        delete t;
        _size--;
    }


private:
    struct ListNode {
        int val;
        ListNode* next;
        explicit ListNode(int x) : val(x), next(nullptr) {}
        ListNode() :val(0), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };
    ListNode* _dummyHead;
    int _size;
};

//int main() {
//    MyLinkedList linkedList = MyLinkedList();
//    linkedList.addAtHead(1);
//    linkedList.addAtTail(3);
//    linkedList.addAtIndex(1, 2);
//    linkedList.printLinkedList();
//    std::cout << linkedList.get(1) << std::endl;
//    linkedList.deleteAtIndex(1);
//    linkedList.printLinkedList();
//    std::cout << linkedList.get(1) << std::endl;
//    MyLinkedList2 linkedList = MyLinkedList2();
//    linkedList.deleteAtIndex(0);
//}