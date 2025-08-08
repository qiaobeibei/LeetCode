/*
����һ��������, �ҵ�����������ָ���ڵ������������ȡ�

�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T �������ڵ� p��q������������ȱ�ʾΪһ���ڵ� x��
���� x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����
*/


/*
�ʣ�Ϊʲô���ֵ�ǰ�ڵ��� p ���� q �Ͳ������µݹ��ˣ���һ������ q ���� p �أ�

����������� q ���� p����ô��ǰ�ڵ��������������ȣ�ֱ�ӷ��ص�ǰ�ڵ㡣�������û�� q �� p��
�Ǽ�Ȼ��û��Ҫ�ҵĽڵ��ˣ�Ҳ����Ҫ�ݹ飬ֱ�ӷ��ص�ǰ�ڵ㡣
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
// ������ƵĻ��У������������������������ȣ�https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr or root == p or root == q) {
            return root;
        }
        // �ֱ�������������������Ѱ�� p �� q �������������
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        /*
        ������������������ĵݹ���ö������˷ǿ�ָ�룬˵�� p �� q �ֱ�λ�ڵ�ǰ�ڵ� root 
        �����������У���ô��ǰ�ڵ� root �������ǵ�����������ȣ����� root
        */
        if (left and right) {
            return root;
        }
        /*
        ���ֻ���������ĵݹ���÷����˷ǿ�ָ�룬˵�� p �� q �����������У���ô���������
        �Ⱦ����������У����� left
        */
        if (left) {
            return left;
        }
        return right;
    }
};


