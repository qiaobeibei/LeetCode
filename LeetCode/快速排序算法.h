#pragma once

#include <iostream>
#include <vector>

int Partition(std::vector<int>&, int, int);
void QuickSort(std::vector<int>&, int, int);

int Partition(std::vector<int>& A, int low, int high) {
	int pivot = A[low];									// 选择基准元素
	while (low < high) {								// 用左右指针搜索基准的最终位置
		while (low < high and A[high] >= pivot) --high;	// 退出循环仅有两种可能，那就是A[high] < pivot；low == high
		A[low] = A[high];								// 比基准小的元素移动到左端
		while (low < high and A[low] <= pivot) ++low;
		A[high] = A[low];								// 比基准大的元素移动到右端
	}
	A[low] = pivot;										// 基准存放到最终位置(low == high)
	return low;
}

void QuickSort(std::vector<int>& A, int low, int high) {
	if (low < high) {									// 递归跳出的条件
		int pivotpos = Partition(A, low, high);			// 划分
		QuickSort(A, low, pivotpos - 1);				// 划分左子表
		QuickSort(A, pivotpos + 1, high);				// 划分左子表
	}
}
