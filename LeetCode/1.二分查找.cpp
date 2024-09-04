#include <iostream>
#include <vector>

/*����һ�� n ��Ԫ������ģ������������� nums ��һ��Ŀ��ֵ target  ��д
һ���������� nums �е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1��*/

//����ұ�д��(����)
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;                                   //��߽�
        int right = nums.size() - 1;                    //�ұ߽�
        int middle = 0;                                 //�м�ֵ
        while (left <= right) {                         //����ұ������У�left==right����ʵ�֣�����ӦΪleft <= right
            middle = (left + right) / 2;
            if (nums[middle] > target)
                /*//��Ϊnums[middle] > target�������ұ߽粻��Ҫ����Ϊmiddle����Ϊ����Ϊmiddle����ܻ�
                ��ɨ��һ���ұ߽��˷���Դ����Ϊ������ұ߽粻������target����������Ϊmiddle-1*/
                right = middle - 1;
            else if (nums[middle] < target)
                left = middle + 1;                      //ͬ��������Ϊmiddle�˷���Դ����Ϊmiddle+1
            else
                return middle;
        }
        return -1;
    }
};

//����ҿ�д��(����)
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;                    
        int middle = 0;                                 
        while (left < right) {                          //����ҿ������У�left==right������ʵ�֣�����ӦΪleft < right
            middle = (left + right) / 2;
            if (nums[middle] > target)
                right = middle;                         //����������ҿ�������ɨ���ұ߽�����Ӧ��Ϊmiddle
            else if (nums[middle] < target)
                left = middle + 1;                      //��գ�������߽�Ҫ��һ�������˷���Դ
            else
                return middle;
        }
        return -1;
    }
};


//����ұ�д��(����)
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, middle;
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] < target)
                right = middle - 1;
            else if (nums[middle] > target)
                left = middle + 1;
            else
                return middle;
        }
        return -1;
    }
};