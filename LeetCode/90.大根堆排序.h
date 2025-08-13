#pragma once

#include <iostream>
#include <tuple>

void HeadAdjust(int A[], int k, int len);
void BuildMaxHeap(int A[], int len);
void HeapSort(int A[], int len);

// ��kΪ������������Ϊ�����
void HeadAdjust(int A[], int k, int len) {
	A[0] = A[k];									// A[0]�ݴ������ĸ���㣬�Է�������
	// i=2kָ��������ӣ�2k+1ָ������Һ���
	for (int i = 2 * k; i < len; i *= 2) {			// ��key�ϴ���ӽ������ɸѡ
		if (i < len and A[i] < A[i + 1]) i++;		// �Ա����Һ��ӵ�ֵ��ȡkey�ϴ���ӽ����±�
		if (A[0] >= A[i]) break;					// ���ӵ�ֵС�ڸ���㣬ɸѡ����
		else {
			A[k] = A[i];							// ��A[i]������˫�׽����
			k = i;									// �޸�kֵ���Ա��������ɸѡ
		}
	}
	A[k] = A[0];									// ��ɸѡ����ֵ��������λ��
}

// ���������
void BuildMaxHeap(int A[], int len) {
	// ����һ����ʼ���У������г��ȵ�һ�룬��len/2��ʼ��������Ϊlen/2��Ӧ�����Ľ�㣬len/2��Ķ���Ҷ����޺���
	// ��len/2С�Ķ��ǽ�㣬�к��ӣ�����i--
	for (int i = len / 2; i > 0; i--)				// �Ӻ���ǰ�������з��ն˽��
		HeadAdjust(A, i, len);
}

// ������������߼�
void HeapSort(int A[], int len) {
	BuildMaxHeap(A, len);							// ��ʼ����
	for (int i = len; i > 1; i--) {					// n-1�ɵĽ����ͽ��ѹ���
		std::tie(A[i], A[1]) = std::make_tuple(A[1], A[i]);	// �Ѷ�Ԫ�غͶѵ�Ԫ�ؽ���
		HeadAdjust(A, 1, i - 1);					// ��ʣ��Ĵ�����Ԫ������ɶ�
	}
}