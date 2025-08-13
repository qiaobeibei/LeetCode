#pragma once

#include <iostream>
#include <tuple>

void HeadAdjust(int A[], int k, int len);
void BuildMaxHeap(int A[], int len);
void HeapSort(int A[], int len);

// 以k为根的子树调整为大根堆
void HeadAdjust(int A[], int k, int len) {
	A[0] = A[k];									// A[0]暂存子树的根结点，以防被覆盖
	// i=2k指向结点的左孩子，2k+1指向结点的右孩子
	for (int i = 2 * k; i < len; i *= 2) {			// 沿key较大的子结点向下筛选
		if (i < len and A[i] < A[i + 1]) i++;		// 对比左右孩子的值，取key较大的子结点的下标
		if (A[0] >= A[i]) break;					// 孩子的值小于根结点，筛选结束
		else {
			A[k] = A[i];							// 将A[i]调整到双亲结点上
			k = i;									// 修改k值，以便继续向下筛选
		}
	}
	A[k] = A[0];									// 被筛选结点的值放入最终位置
}

// 建立大根堆
void BuildMaxHeap(int A[], int len) {
	// 给定一个初始序列，从序列长度的一半，即len/2开始调整，因为len/2对应着最大的结点，len/2后的都是叶结点无孩子
	// 比len/2小的都是结点，有孩子，所以i--
	for (int i = len / 2; i > 0; i--)				// 从后往前调整所有非终端结点
		HeadAdjust(A, i, len);
}

// 堆排序的完整逻辑
void HeapSort(int A[], int len) {
	BuildMaxHeap(A, len);							// 初始建堆
	for (int i = len; i > 1; i--) {					// n-1躺的交换和建堆过程
		std::tie(A[i], A[1]) = std::make_tuple(A[1], A[i]);	// 堆顶元素和堆底元素交换
		HeadAdjust(A, 1, i - 1);					// 把剩余的待排序元素整理成堆
	}
}