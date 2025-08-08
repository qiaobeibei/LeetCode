/*
����һ�� n �� n �Ķ�ά���� matrix ��ʾһ��ͼ�����㽫ͼ��˳ʱ����ת 90 �ȡ�

������� ԭ�� ��תͼ������ζ������Ҫֱ���޸�����Ķ�ά�����벻Ҫ ʹ����һ����������תͼ��
*/

#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

// �Ƚ����󰴶Խ��߷�ת��Ȼ��ÿһ��Ԫ���ٴη�ת
class Solution {
private:
    // ��ʵ����һ�� 3*3 ���󼴿ɣ���һ����Ҫ��ת��Ԫ���ǣ�0��1���ͣ�1��0��������i��0��ʼ��j��i+1��ʼ
    void matrixTranspose(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        matrixTranspose(matrix);
        for (auto& vec : matrix) {
            std::reverse(vec.begin(), vec.end());
        }
    }
};