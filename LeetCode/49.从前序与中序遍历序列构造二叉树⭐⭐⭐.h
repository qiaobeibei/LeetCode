/*
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， 
inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
*/

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<unordered_map>
// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=study-plan-v2&envId=top-100-liked
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
/*
前序遍历：按照「根-左子树-右子树」的顺序遍历二叉树。
中序遍历：按照「左子树-根-右子树」的顺序遍历二叉树。
后序遍历：按照「左子树-右子树-根」的顺序遍历二叉树。

前序遍历的第一个元素是根，中序遍历根元素的左边是它的左子树，右边是它的右子树
右子树中在前序遍历的第一个元素是右子树的根
左子树中在前序遍历的第一个元素是左子树的根

举例：
    3
   / \
  9  20
    /  \
   15   7
前序遍历结果是 [3, 9, 20, 15, 7]，中序遍历结果是 [9, 3, 15, 20, 7]。



*/
class Solution {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        
        int n = preorder.size();
        std::unordered_map<int, int> index; // 存储中序遍历中每个元素对应的索引
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
             
        std::function<TreeNode* (int pre_l, int pre_r, int in_l, int in_r)> dfs =
            [&](int pre_l, int pre_r, int in_l, int in_r)->TreeNode* {
            // 如果前序遍历的左边界等于右边界，说明该区间没有节点，返回空指针
            if (pre_l == pre_r) return nullptr;
            // 前序遍历的第一个元素就是当前子树的根节点
            // 计算左子树的大小，即根节点在中序遍历中的位置减去中序遍历的左边界
            int left_size = index[preorder[pre_l]] - in_l; 
            // 递归构建左子树
            // 前序遍历中左子树的范围是 [pre_l + 1, pre_l + 1 + left_size)
            // 中序遍历中左子树的范围是 [in_l, in_l + left_size)
            // 因为前序遍历中根结点在第一位，所以左子树必须先对左边界+1跳过第一位元素
            // 而中序遍历中左子树从边界开始，所以左子树的左边界不用+1，但是右子树必须对右边界+1跳过根元素
            TreeNode* left = dfs(pre_l + 1, pre_l + 1 + left_size, in_l, in_l + left_size);
            // 递归构建右子树
            // 前序遍历中右子树的范围是 [pre_l + 1 + left_size, pre_r)
            // 中序遍历中右子树的范围是 [in_l + 1 + left_size, in_r)
            // 前序的右子树和左子树紧挨着，所以右子树的左边界就是左子树的有边界
            // 中序的右子树左边是根，所以必须先将边界+1跳过根元素
            TreeNode* right = dfs(pre_l + 1 + left_size, pre_r, in_l + 1 + left_size, in_r);
            return new TreeNode(preorder[pre_l], left, right);
        };
        // 前序遍历的范围是[0, n)，中序遍历的范围是[0, n)
        return dfs(0, n, 0, n); // 左开右闭区间
    }
};