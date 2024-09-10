/*
�����ѡ��ʹ�õ��������˫������Ʋ�ʵ���Լ�������

�������еĽڵ�Ӧ�þ߱��������ԣ�val �� next ��val �ǵ�ǰ�ڵ��ֵ��next ��ָ����һ���ڵ��ָ��/���á�

�����˫����������Ҫ���� prev ��ָʾ�����е���һ���ڵ㡣���������е����нڵ��±�� 0 ��ʼ��

ʵ�� MyLinkedList �ࣺ

MyLinkedList() ��ʼ�� MyLinkedList ����
int get(int index) ��ȡ�������±�Ϊ index �Ľڵ��ֵ������±���Ч���򷵻� -1 ��
void addAtHead(int val) ��һ��ֵΪ val �Ľڵ���뵽�����е�һ��Ԫ��֮ǰ���ڲ�����ɺ��½ڵ���Ϊ����ĵ�һ���ڵ㡣
void addAtTail(int val) ��һ��ֵΪ val �Ľڵ�׷�ӵ���������Ϊ��������һ��Ԫ�ء�
void addAtIndex(int index, int val) ��һ��ֵΪ val �Ľڵ���뵽�������±�Ϊ index �Ľڵ�֮ǰ����� index ��������ĳ��ȣ���ô�ýڵ�ᱻ׷�ӵ������ĩβ����� index �ȳ��ȸ��󣬸ýڵ㽫 ������� �������С�
void deleteAtIndex(int index) ����±���Ч����ɾ���������±�Ϊ index �Ľڵ㡣
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

// ��ȡ�����е� index ���ڵ��ֵ�����������Ч���򷵻�-1
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
// ������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪ val �Ľڵ㡣������½ڵ㽫��Ϊ����ĵ�һ���ڵ�
void MyLinkedList::addAtHead(int val) {
    auto head = new ListNode(val);
    head->next = _dummyHead->next;
    _dummyHead->next = head;
    _size++;
}
// ��ֵΪ val �Ľڵ�׷�ӵ���������һ��Ԫ��
void MyLinkedList::addAtTail(int val) {
    auto cur = _dummyHead;
    while (cur->next != nullptr) 
        cur = cur->next;
    cur->next = new ListNode(val);
    _size++;
}
// �������еĵ� index ���ڵ�֮ǰ���ֵΪ val  �Ľڵ㡣��� index ��������ĳ��ȣ���ýڵ�
// �����ӵ������ĩβ����� index ���������ȣ��򲻻����ڵ㡣���indexС��0������ͷ������ڵ�
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
// ������� index ��Ч����ɾ�������еĵ� index ���ڵ�
void MyLinkedList::deleteAtIndex(int index) {
    if (index< 0 || index > _size - 1) return;//indexֵ��Ч��ֱ�ӷ���
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

// ��ӡ����
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
    
    int get(int index) {// ��ȡ�����е�index���ڵ��ֵ
        if (index <0 or index > _size - 1) return -1;
        auto head = _dummyHead->next;
        while (index--) head = head->next;
        return head->val;
    }
    void addAtHead(int val) {// ������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪval�Ľڵ�
        auto newNode = new ListNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    void addAtTail(int val) {// ��ֵΪval�Ľڵ�׷�ӵ���������һ��Ԫ��
        auto cur = _dummyHead;
        while (cur->next != nullptr) cur = cur->next;
        cur->next = new ListNode(val);
        _size++;
    }

    void addAtIndex(int index, int val) {//������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪval�Ľڵ�
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
    void deleteAtIndex(int index) {// ɾ�������еĵ�index���ڵ�
        if (index<0 || index>_size - 1) return;//indexֵ��Ч��ֱ�ӷ���
        ListNode* cur = _dummyHead, * t = nullptr;
        while (index--) cur = cur->next;   // �ҵ���index-1�����
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