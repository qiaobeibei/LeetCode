//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//namespace day3_2 {
//    /*
//����һ������ n ���������������һ�������� target ��
//
//�ҳ����������������ܺʹ��ڵ��� target �ĳ�����С��
//������[numsl, numsl+1, ..., numsr-1, numsr] ���������䳤�ȡ���������ڷ��������������飬���� 0 ��
//*/
//
//
////��������
//    class Solution {
//    public:
//        int minSubArrayLen(int target, std::vector<int>& nums) {
//            if (nums.empty())  return 0;
//            else if (nums.size() == 1)  return nums[0] >= target ? 1 : 0;
//            else if (nums[0] >= target)  return 1;
//
//            int sums = 0;                                       // ���廬������ֵ֮��
//            int result = INT_MAX;
//            // left�ǻ���������ָ�룬right�ǻ���������ָ��
//            for (int left = 0, right = 0; right <= nums.size() - 1; right++) {
//                sums += nums[right];
//                // ��ǰ������������ֵ֮�ʹ���Ŀ��ֵ���Ըô��ڽ�����������
//                while (sums >= target) {
//                    // ��¼��̴��ڳ���
//                    result = result < right - left + 1 ? result : right - left + 1;
//                    // �������ڳ���
//                    sums -= nums[left++];
//                }
//            }
//            // ��result��ֵ���䣬��ôû���Ӵ�������������֮������
//            return result == INT_MAX ? 0 : result;
//        }
//    };
//
//
//    class Solution {
//    public:
//        int minSubArrayLen(int target, std::vector<int>& nums) {
//            int sum = 0;                                        // ����������ֵ֮��
//            int subL;                                           // �������ڳ���
//            int result = INT_MAX;
//            // i�ǻ������ڳ�ʼλ�ã�j�ǻ��������ն�λ�ã����߳�ʼֵ��Ϊ0
//            for (int i = 0, j = 0; j <= nums.size() - 1; j++) {
//                sum += nums[j];
//                // ע������ʹ��while��ÿ�θ��� i����ʼλ�ã��������ϱȽ��������Ƿ��������
//                while (sum >= target) {
//                    subL = j - i + 1;                           // ȡ�������ڳ���
//                    result = result < subL ? result : subL;     // ȡ���ڵ���Сֵ
//                    // result = std::min(result, subL);
//                    // �������ֳ��������ڵľ���֮��������Ӵ��ʹ���Ŀ��ֵ���򲻶ϱ��i�������е���ʼλ�ã�
//                    sum -= nums[i++];
//                }
//            }
//            // ���resultû�б���ֵ�Ļ����ͷ���0��˵��û�з���������������
//            return result == INT_MAX ? 0 : result;
//        }
//    };
//
//
//}