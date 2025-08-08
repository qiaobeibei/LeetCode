//https://leetcode.cn/problems/min-stack/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <stack>
#include <mutex>
#include <condition_variable>

class MinStack {
private:
    std::stack<int> _data;
    std::stack<int> _min_value;
    mutable std::mutex _m;
public:
    MinStack() { }

    MinStack(const MinStack& other) {
        std::lock_guard<std::mutex> lk(_m);
        _data = other._data;
        _min_value = other._min_value;
    }
    MinStack& operator=(const MinStack& other) {
        if (this != &other) {
            std::lock_guard<std::mutex> lk(_m);
            _data = other._data;
            _min_value = other._min_value;
        }
        return *this;
    }

    void push(int val) {
        std::lock_guard<std::mutex> lk(_m);
        _data.push(std::move(val));
        if (_min_value.empty() || _min_value.top() >= val) {
            _min_value.push(val);
        }
    }

    void pop() {
        std::lock_guard<std::mutex> lock(_m);
        if (_data.empty()) {
            return throw std::out_of_range("Stack is empty, cannot pop element.");
        }
        if (_data.top() == _min_value.top()) {
            _min_value.pop();
        }
        _data.pop();
    }

    int top() {
        std::lock_guard<std::mutex> lock(_m);
        if (_data.empty()) {
            throw std::out_of_range("Stack is empty, cannot get top element.");
        }
        return _data.top();
    }

    int getMin() {
        std::lock_guard<std::mutex> lock(_m);
        if (_min_value.empty()) {
            throw std::out_of_range("Stack is empty, cannot get minimum value.");
        }
        return _min_value.top();
    }
};
