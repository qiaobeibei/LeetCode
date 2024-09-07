#pragma once

#include <iostream>
#include <vector>

int Partition(std::vector<int>&, int, int);
void QuickSort(std::vector<int>&, int, int);

int Partition(std::vector<int>& A, int low, int high) {
	int pivot = A[low];									// ѡ���׼Ԫ��
	while (low < high) {								// ������ָ��������׼������λ��
		while (low < high and A[high] >= pivot) --high;	// �˳�ѭ���������ֿ��ܣ��Ǿ���A[high] < pivot��low == high
		A[low] = A[high];								// �Ȼ�׼С��Ԫ���ƶ������
		while (low < high and A[low] <= pivot) ++low;
		A[high] = A[low];								// �Ȼ�׼���Ԫ���ƶ����Ҷ�
	}
	A[low] = pivot;										// ��׼��ŵ�����λ��(low == high)
	return low;
}

void QuickSort(std::vector<int>& A, int low, int high) {
	if (low < high) {									// �ݹ�����������
		int pivotpos = Partition(A, low, high);			// ����
		QuickSort(A, low, pivotpos - 1);				// �������ӱ�
		QuickSort(A, pivotpos + 1, high);				// �������ӱ�
	}
}
