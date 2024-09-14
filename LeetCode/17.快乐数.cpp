/*
��дһ���㷨���ж�һ���� n �ǲ��ǿ�������

���������� ����Ϊ��

����һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ���͡�
Ȼ���ظ��������ֱ���������Ϊ 1��Ҳ������ ����ѭ�� ��ʼ�ձ䲻�� 1��
���������� ���Ϊ 1����ô��������ǿ�������
��� n �� ������ �ͷ��� true �����ǣ��򷵻� false ��
*/

#include <iostream>
#include <unordered_set>
#include <unordered_map>

/*
���ⲻ�����ü��ϼ�¼ÿ�εļ��������ж��Ƿ����ѭ������Ϊ������Ͽ��ܴ��޷��洢��
���⣬Ҳ������ʹ�õݹ飬ͬ������ݹ��ν����ֱ�ӵ��µ���ջ��������Ҫ��Ϊ���
��Ŀ������������ int �Ͷ�Ͷ��ȡ�ɡ�

ʹ�� ������ָ�롱 ˼�룬�ҳ�ѭ��������ָ�롱 ÿ��������������ָ�롱 ÿ����һ������
�������ʱ����Ϊһ��ѭ�����ڡ���ʱ���ж��ǲ�����Ϊ 1 �����ѭ�����ǵĻ����ǿ�������
�����ǿ�������
ע������������õ�Ҳ�Ǹ÷���
*/
// ����ָ��
class Solution {
public:
    int getSum(int n) { // �ú�����n���������ÿһλ��ƽ��֮��
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int right = n, left = n;
        do {
            left = getSum(left); // left��һ��
            right = getSum(right); // right������
            right = getSum(right);
        } while (right != left); 
        // �˳�ѭ��ֻ�������������һ�����л��Σ���ôleft��=1������false���ڶ����ǿ�������1��ƽ����Ȼ��1��
        // Ҳ���˳�ѭ��������ʱ����true��
        return left == 1;
    }
};

// �ݹ�
class Solution {
public:
    std::unordered_map<int, bool> map;

    bool isHappy(int n) {
        int temp = 0;
        while (n) {
            temp += (n % 10) * (n % 10);
            n /= 10;
        }
        // map.find(temp)���ڲ���temp�Ƿ���map�У�������ڣ�����һ��ָ���Ԫ�صĵ���������֮�����س�βend()
        if (map.find(temp) != map.end()) { 
            return false;
        }
        map[temp] = true;
        // �ݹ����������remp==1������true�����أ�����ݹ�
        return temp == 1 || isHappy(temp);
    }
};

// ���ϼ�¼����ϣ��
class Solution {
public:
    int getSum(int n) { // �ú�����n���������ÿһλ��ƽ��֮��
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        if (n == 1) return true;

        std::unordered_set<int> temp;
        while (n != 1) {
            n = getSum(n);
            if(!temp.erase(n)) // ���erase̫����
                temp.insert(n);
            else
                return false;
        }
        return true;
    }
};