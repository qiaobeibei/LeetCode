/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
*/


/*
问：为什么发现当前节点是 p 或者 q 就不再往下递归了？万一下面有 q 或者 p 呢？

答：如果下面有 q 或者 p，那么当前节点就是最近公共祖先，直接返回当前节点。如果下面没有 q 和 p，
那既然都没有要找的节点了，也不需要递归，直接返回当前节点。
*/

// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/?envType=study-plan-v2&envId=top-100-liked
#pragma once

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
// 与此相似的还有：求二叉搜索树的最近公共祖先：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr or root == p or root == q) {
            return root;
        }
        // 分别在左子树和右子树中寻找 p 和 q 的最近公共祖先
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        /*
        如果左子树和右子树的递归调用都返回了非空指针，说明 p 和 q 分别位于当前节点 root 
        的左右子树中，那么当前节点 root 就是它们的最近公共祖先，返回 root
        */
        if (left and right) {
            return root;
        }
        /*
        如果只有左子树的递归调用返回了非空指针，说明 p 和 q 都在左子树中，那么最近公共祖
        先就在左子树中，返回 left
        */
        if (left) {
            return left;
        }
        return right;
    }
};


