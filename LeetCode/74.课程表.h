//https://leetcode.cn/problems/course-schedule/solutions/2992884/san-se-biao-ji-fa-pythonjavacgojsrust-by-pll7/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>
#include<functional>

// ����һ������ͼ����ÿ�� prerequisites[i]=[a,b] ����һ������� b��a������һ������ͼ g�����ж�ͼ���Ƿ��л�
// �Ƿ����һ��˳��ʹ�����пγ̶��б���ɣ���ͼ���޻���

/*
ͨ���������������DFS������ͼ����������ɫ��ǽڵ�״̬������Ƿ���ڻ���
0��δ���ʣ����ڵ���δ�����ʡ�
1�����ڷ��ʣ����ڵ��ѱ����ʣ�����δ��ɶ��������ڽӽڵ�ķ��ʣ���ǰ�ڵݹ�ջ�У����ڵ�ǰ·������
2������ɣ����ڵ㼰�������ڽӽڵ��ѷ�����ϣ��ݹ�ջ���ѵ�������
���ļ���߼���
����ڷ��ʽڵ� x ���ڽӽڵ� y ʱ������ y ����ɫΪ 1�����ڷ��ʣ���˵�� y �ڵ�ǰ·���У�
���ڻ���x �� ... �� y �� x����
*/
class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        // g ���ڽӱ�g[b] �洢������ b Ϊ��������ߵ��յ㣨�� b �ĺ����γ̣�
        // ���磬prerequisites = [[0,1]] ��ʾ���γ� 0 �����޿��� 1������Ӧ�� 1 �� 0����� g[1] = [0]���� g[1] = [0,2,3...]
        std::vector<std::vector<int>> g(numCourses);
        for (auto& p : prerequisites) {
            g[p[1]].push_back(p[0]);  // ��ÿ�� prerequisites[i] = [a, b] ����һ������� b��a
        }

        std::vector<int> colors(numCourses);  // 0:δ���ʣ�1:���ڷ��ʣ�2:�����
        std::function<bool(int x)> dfs = [&](int x) -> bool {
            colors[x] = 1; // x ���ڷ�����
            for (int y : g[x]) { // ����γ�0�����޿ɳ���1���γ�2�����޿γ�Ҳ��1����g[1]=[0,2]
                // �����ǰѧϰ�γ̵ĺ����γ̴��ڡ����ڷ����С����ߺ����γ̡�δ�����ʡ������Ǻ����γ���Ϊ����ʱ����
                // �����д��ڻ��򷵻�true
                if (colors[y] == 1 || colors[y] == 0 && dfs(y)) {
                    return true; // �л�
                }
            }
            colors[x] = 2; // x �������
            return false; // û�л�
        };

        // ͼ�����ɶ������ͨ����ͼ��ɣ������Ҫ�������нڵ㣬��ÿ��δ���ʵĽڵ����� DFS��
        for (int i = 0; i < numCourses; ++i) {
            if (colors[i] == 0 && dfs(i)) {
                return false; // �л�
            }
        }
        return true; // û�л�

    }
};