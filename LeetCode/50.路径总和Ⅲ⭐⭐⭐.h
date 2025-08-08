/*
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
*/

// https://leetcode.cn/problems/path-sum-iii/description/?envType=study-plan-v2&envId=top-100-liked
#pragma once
#include<iostream>
#include<unordered_map>
#include<functional>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
// 这道题目和“和为K的子数组”相似
/*
必须要恢复现场：
如果不恢复现场，当我们递归完左子树，要递归右子树时，cnt 中还保存着左子树的数据。
但递归到右子树，要计算的路径并不涉及到左子树的任何节点，如果不恢复现场，cnt 中
统计的前缀和个数会更多，我们算出来的答案可能比正确答案更大。

举例：
目标和 targetSum = 8
    10
   /  \
  5   -3
 / \    \
3   2    11
因为我们先查左子树，所以左子树中  s = 10 + 5 + 3 = 18 是一条路，我们通过 prefixSum[s - targetSum] 即
prefixSum[18 - 8] = prefixSum[10] 来计算以节点 3 结尾且路径和等于 8 的路径数量，此时为 1。

接着，我们会递归遍历节点 3 的左子树（如果存在）和右子树（如果存在）。
当完成对节点 3 及其子树的遍历后，递归会回溯到节点 5。此时，如果不将 
prefixSum[18] 的计数减 1，那么在后续遍历节点 5 的右子树（节点 2）时，
prefixSum 中记录的 prefixSum[18] 就会包含从根节点到节点 3 的路径信息，
这会导致错误地计算以节点 2 结尾且路径和等于 8 的路径数量。


*/
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        std::unordered_map<long long, int> prefixSum;
        prefixSum[0] = 1;

        std::function<void(TreeNode* node, long long s)> dfs =
            [&](TreeNode* node, long long s) {
            if (node == nullptr) return;

            s += node->val;
            // 必须先加 ans 后加 prefixSum，因为当 targetSum = 0 时先加 prefixSum 会出错
            ans += prefixSum.find(s - targetSum) != prefixSum.end() ? prefixSum[s - targetSum] : 0;
            prefixSum[s]++;

            dfs(node->left, s);
            dfs(node->right, s);
            prefixSum[s]--; // 恢复现场
        };
        dfs(root, 0);
        return ans;

    }
};
