#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>

//https://leetcode.cn/problems/longest-increasing-subsequence/?envType=study-plan-v2&envId=top-100-liked
// �����Ŀ�͡�3.��������С��������е��񣬵���ʵ��ͬ
class Solution {
public:
    /*
    Ҫ�ҳ�һ������������������еĳ��ȣ����ǿ��Զ���һ������ dfs(i) ����ʾ�������е� i ��Ԫ�� 
    nums[i] ��β������������еĳ��ȣ�memo[i] ���ڼ�¼������ȡ�����ÿ��Ԫ�� nums[i]��������Ҫ��
    ����֮ǰ������Ԫ�� nums[j]������ j < i������� nums[j] < nums[i]����ô˵�����Խ� nums[i] ������ 
    nums[j] ��β�ĵ��������к��棬�Ӷ��õ�һ���µĵ��������С�ͨ���Ƚ����п��ܵ���������Ǿ����ҵ���
    nums[i] ��β������������еĳ��ȡ�
    */

    // [10, 9, 2, 5, 3, 7, 101, 18]
    // ע�⣺����dfs�������һ����һ����dfs(j)һ����dfs(i)
    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> memo(n); // ���ڼ��仯����ʼֵ��Ϊ 0

        std::function<int(int i)> dfs = [&](int i)->int {
            int& res = memo[i]; // ����������
            if (res > 0) {
                return res;  // ��� memo[i] �Ѿ���������� res > 0����ֱ�ӷ��ؽ���������ظ�����
            }
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    // ��� nums[j] С�� nums[i]��˵�����Խ� nums[i] ������ nums[j] ��β�ĵ��������к���
                    // ȡ��ǰ res �� dfs(j) �����ֵ������ res
                    // ע�⣬���ﲻ�ܸ�Ϊres = std::max(res, memo[j])����Ϊֻ�������� nums[k] < nums[j]��k < j���������£�
                    // �Ż���� memo[j]�������п���memo[j]��ʱ��0�����Ա���ݹ����
                    res = std::max(res, dfs(j)); 
                }
            }

            // ע�⣬��Ϊres�����ã����������++resͬʱ���memo�е�Ԫ�ؽ����޸ģ���������ֻ��
            // ����++res�������ܷ���res+1�������޷��޸�memo�е�Ԫ��
            return ++res; // ���ս��Ҫ�� 1����Ϊ��ǰԪ�� nums[i] ����Ҳ��һ������
            // ��ʵ����������ҵ���0~i-1������У�������ҵ���˵���ܽ�nums[i]�ӵ����棬��++res��
            // ���û�ҵ�����memo[i]��Ϊ1��++res��
        };

        int ans = 0; // ���ڼ�¼ȫ������������еĳ���
        for (int i = 0; i < n; i++) {
            // ���������е�ÿ��Ԫ�أ������Ը�Ԫ�ؽ�β������������еĳ���
            ans = std::max(ans, dfs(i));
        }
        return ans;
    }
};

// ��ӡ����������
class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        std::vector<int> memo(n, 0);      // �洢�����
        std::vector<int> prev(n, -1);     // �洢ǰ������

        std::function<int(int)> dfs = [&](int i) {
            if (memo[i] != 0) return memo[i];

            int max_len = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    int current = dfs(j);  // �ݹ�������
                    if (current > max_len) {
                        max_len = current;
                        prev[i] = j;      // �ؼ��޸ģ���¼ǰ���ڵ�
                    }
                }
            }
            memo[i] = max_len + 1;
            return memo[i];
        };

        // ��������Ȳ���¼�յ�
        int max_len = 0, end = -1;
        for (int i = 0; i < n; ++i) {
            int current = dfs(i);
            if (current > max_len) {
                max_len = current;
                end = i;
            }
        }

        // ���ݹ���·��
        std::vector<int> path;
        while (end != -1) {
            path.push_back(nums[end]);
            end = prev[end];
        }
        std::reverse(path.begin(), path.end());

        // ��ӡ���
        std::cout << "LIS: ";
        for (int num : path) std::cout << num << " ";
        std::cout << "\n";

        return max_len;
    }
};

/* ʾ���÷���
���룺{10,9,2,5,3,7,101,18}
�����LIS: 2 5 7 101
      ����ֵ��4
*/