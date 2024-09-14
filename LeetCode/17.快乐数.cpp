/*
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
*/

#include <iostream>
#include <unordered_set>
#include <unordered_map>

/*
此题不建议用集合记录每次的计算结果来判断是否进入循环，因为这个集合可能大到无法存储；
另外，也不建议使用递归，同理，如果递归层次较深，会直接导致调用栈崩溃。不要因为这个
题目给出的整数是 int 型而投机取巧。

使用 “快慢指针” 思想，找出循环：“快指针” 每次走两步，“慢指针” 每次走一步，当
二者相等时，即为一个循环周期。此时，判断是不是因为 1 引起的循环，是的话就是快乐数，
否则不是快乐数。
注：环形链表Ⅱ用的也是该方法
*/
// 快慢指针
class Solution {
public:
    int getSum(int n) { // 该函数求n这个整数中每一位的平方之和
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int right = n, left = n;
        do {
            left = getSum(left); // left走一步
            right = getSum(right); // right走两步
            right = getSum(right);
        } while (right != left); 
        // 退出循环只有两种情况。第一种是有环形，那么left！=1，返回false；第二种是快乐数，1的平方仍然是1，
        // 也会退出循环，但此时返回true。
        return left == 1;
    }
};

// 递归
class Solution {
public:
    std::unordered_map<int, bool> map;

    bool isHappy(int n) {
        int temp = 0;
        while (n) {
            temp += (n % 10) * (n % 10);
            n /= 10;
        }
        // map.find(temp)用于查找temp是否在map中，如果存在，返回一个指向该元素的迭代器；反之，返回超尾end()
        if (map.find(temp) != map.end()) { 
            return false;
        }
        map[temp] = true;
        // 递归条件，如果remp==1，返回true；返回，进入递归
        return temp == 1 || isHappy(temp);
    }
};

// 集合记录（哈希表）
class Solution {
public:
    int getSum(int n) { // 该函数求n这个整数中每一位的平方之和
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        if (n == 1) return true;

        std::unordered_set<int> temp;
        while (n != 1) {
            n = getSum(n);
            if(!temp.erase(n)) // 这个erase太妙了
                temp.insert(n);
            else
                return false;
        }
        return true;
    }
};