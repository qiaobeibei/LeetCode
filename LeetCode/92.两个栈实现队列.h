// https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/description/
#include <iostream>

class CQueue {
private:
    std::stack<int> A, B;
public:
    CQueue() {
   
    }
    
    void appendTail(int value) {
        A.push(value);
    }
    
    int deleteHead() {
        if (!B.empty()) {
          int temp = B.top();
          B.pop();
          return temp;
        }
        if (A.empty()) {
          return -1;
        }
        while (!A.empty()) {
          int temp = A.top();
          A.pop();
          B.push(temp);
        }
        int temp = B.top();
        B.pop();
        return temp;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */