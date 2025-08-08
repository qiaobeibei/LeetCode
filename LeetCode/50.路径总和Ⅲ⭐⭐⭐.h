/*
����һ���������ĸ��ڵ� root ����һ������ targetSum ����ö�������ڵ�ֵ֮�͵��� targetSum �� ·�� ����Ŀ��

·�� ����Ҫ�Ӹ��ڵ㿪ʼ��Ҳ����Ҫ��Ҷ�ӽڵ����������·��������������µģ�ֻ�ܴӸ��ڵ㵽�ӽڵ㣩��
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
// �����Ŀ�͡���ΪK�������顱����
/*
����Ҫ�ָ��ֳ���
������ָ��ֳ��������ǵݹ�����������Ҫ�ݹ�������ʱ��cnt �л������������������ݡ�
���ݹ鵽��������Ҫ�����·�������漰�����������κνڵ㣬������ָ��ֳ���cnt ��
ͳ�Ƶ�ǰ׺�͸�������࣬����������Ĵ𰸿��ܱ���ȷ�𰸸���

������
Ŀ��� targetSum = 8
    10
   /  \
  5   -3
 / \    \
3   2    11
��Ϊ�����Ȳ���������������������  s = 10 + 5 + 3 = 18 ��һ��·������ͨ�� prefixSum[s - targetSum] ��
prefixSum[18 - 8] = prefixSum[10] �������Խڵ� 3 ��β��·���͵��� 8 ��·����������ʱΪ 1��

���ţ����ǻ�ݹ�����ڵ� 3 ����������������ڣ�����������������ڣ���
����ɶԽڵ� 3 ���������ı����󣬵ݹ����ݵ��ڵ� 5����ʱ��������� 
prefixSum[18] �ļ����� 1����ô�ں��������ڵ� 5 �����������ڵ� 2��ʱ��
prefixSum �м�¼�� prefixSum[18] �ͻ�����Ӹ��ڵ㵽�ڵ� 3 ��·����Ϣ��
��ᵼ�´���ؼ����Խڵ� 2 ��β��·���͵��� 8 ��·��������


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
            // �����ȼ� ans ��� prefixSum����Ϊ�� targetSum = 0 ʱ�ȼ� prefixSum �����
            ans += prefixSum.find(s - targetSum) != prefixSum.end() ? prefixSum[s - targetSum] : 0;
            prefixSum[s]++;

            dfs(node->left, s);
            dfs(node->right, s);
            prefixSum[s]--; // �ָ��ֳ�
        };
        dfs(root, 0);
        return ans;

    }
};
