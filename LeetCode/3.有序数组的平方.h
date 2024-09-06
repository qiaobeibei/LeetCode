//#include <iostream>
//#include <vector>
//
//namespace day3 {
//    /*
//����һ���� �ǵݼ�˳�򣨵����� ������������� nums������ ÿ�����ֵ�ƽ�� ��ɵ������飬Ҫ��Ҳ�� �ǵݼ�˳�� ����
//*/
//
//
///*
//��������Ԫ�ض�����������ôÿ��Ԫ��ƽ�����԰��������У�������и�Ԫ�أ���Ԫ��ƽ�����ֵ��
//�ܻ����������Ԫ�ظ���
//
//�ⷨ1����ֱ�۵��뷨��Ī���ڣ�ÿ����ƽ��֮���Ÿ������ʱ�临�Ӷ��� O(n + nlogn)��
//����˵��O(nlogn)��ʱ�临�Ӷȣ���Ϊ�˺�����˫ָ�뷨�㷨ʱ�临��
//
//�ⷨ2��������ʵ������ģ� ֻ��������ƽ��֮����ܳ�Ϊ������ˡ�
//��ô����ƽ�������ֵ������������ˣ���������߾������ұߣ����������м䡣
//��ʱ���Կ���˫ָ�뷨�ˣ�iָ����ʼλ�ã�jָ����ֹλ�á�
//����һ��������result����A����һ���Ĵ�С����kָ��result������ֹλ�á�
//
//���A[i] * A[i] < A[j] * A[j] ��ôresult[k--] = A[j] * A[j]; ��
//
//���A[i] * A[i] >= A[j] * A[j] ��ôresult[k--] = A[i] * A[i]; ��
//*/
//
////˫ָ��(��ʼ������������)
//    class Solution {
//    public:
//        std::vector<int> sortedSquares(std::vector<int>& nums) {
//            std::vector<int> result(nums.size());
//            int k = nums.size() - 1;               //������Ԫ�ص�λ�򣬴����ֵ��ʼ�洢
//            //i++,j__������ѭ����,ȡ������β�ĸ�Ԫ�ص�ֵ���Ž���������result��
//            for (int i = 0, j = nums.size() - 1; i <= j;) {
//                //�������˵�ֵ��ƽ���϶���һ�������ֵ���������ȱȽ����˵Ĵ�С��Ȼ���𽥱ƽ��м�
//                if (nums[i] * nums[i] > nums[j] * nums[j])
//                    result[k--] = nums[i] * nums[i++];
//                else
//                    result[k--] = nums[j] * nums[j--];
//            }
//            return result;
//        }
//    };
//
//
//    class Solution {
//    public:
//        std::vector<int> sortedSquares(std::vector<int>& nums) {
//            std::vector<int> result(nums.size());
//            int k = nums.size() - 1;
//            for (int i = 0, j = nums.size() - 1; i <= j;) {
//                if (nums[i] * nums[i] < nums[j] * nums[j])
//                    result[k--] = nums[j] * nums[j--];
//                else
//                    result[k--] = nums[i] * nums[i++];
//            }
//            return result;
//        }
//    };
//}