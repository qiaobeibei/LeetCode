/*
��һ�����������ڣ������ֳ���n * m�����������飬ÿ�����鶼ӵ�в�ͬ��Ȩֵ�������������ؼ�ֵ��
Ŀǰ�������ҿ�����˾��A ��˾�� B ��˾��ϣ���������������������ء�

���ڣ���Ҫ�������������������������� A ��˾�� B ��˾��

Ȼ�������ڳ��й滮�����ƣ�ֻ�������򰴺�������򻮷ֳ����������򣬶���ÿ�������򶼱����
��һ���������顣 Ϊ��ȷ����ƽ����������Ҫ�ҵ�һ�ַ��䷽ʽ��ʹ�� A ��˾�� B ��˾���Ե���
�����ڵ������ܼ�ֵ֮����С��

ע�⣺���鲻���ٷ֡�

���룺
	��һ���������������������� n �� m��
	�������� n �У�ÿ����� m ����������
�����
	�����һ�����������������������������ܼ�ֵ֮�����С��ࡣ

	1 <= n, m <= 100��
	n �� m ��ͬʱΪ 1��
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// ǰ׺��
int main() {
	using std::vector;
	using std::cin;
	using std::cout;

	int n, m;
	cin >> n >> m;
	vector<vector<int>>* vec = new vector<vector<int>>(n, vector<int>(m, 0));
	vector<int>* row = new vector<int>(n, 0);
	vector<int>* col = new vector<int>(m, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> (*vec)[i][j];
			(*row)[i] += (*vec)[i][j];						// ������vecÿһ�е�Ԫ��֮�ʹ洢��row
			(*col)[j] += (*vec)[i][j];						// ������vecÿһ�е�Ԫ��֮�ʹ洢��col
		}
		if (i > 0) (*row)[i] += (*row)[(long long)i - 1];	// ��row��Ԫ�ر任Ϊ��ǰԪ����ǰ��Ԫ��֮�ͣ�ǰ׺�ͣ�
	}

	for (int j = 0; j < m; j++)
		if (j != 0)
			(*col)[j] += (*col)[(long long)j - 1];			// ��col��Ԫ�ر任Ϊ��ǰԪ����ǰ��Ԫ��֮�ͣ�ǰ׺�ͣ�


	int result_row = INT_MAX;
	for (int i = 0; i < n - 1; i++)
		// �����󻮷�Ϊ�����ֺ������ֲ����Сֵ
		result_row = std::min(std::abs((*row)[i] - ((*row)[(long long)n - 1] - (*row)[i])), result_row);

	int result_col = INT_MAX;
	for (int j = 0; j < m - 1; j++)
		result_col = std::min(std::abs((*col)[j] - ((*col)[(long long)m - 1] - (*col)[j])), result_col);

	// ���طֱ����к���Ϊ���������ֲ����Сֵ
	cout << std::min(result_row, result_col);

	delete vec, row, col;

	return 0;
}


#include<iostream>
#include<cmath>
using namespace std;
const int N = 110;
int s[N][N];
int n, m, ans = 1e9;
void solve()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			int x;
			cin >> x;
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
		}
	for (int i = 1; i < n; i++)
	{
		int x = abs(s[n][m] - 2 * s[i][m]);
		ans = min(ans, x);
	}
	for (int i = 1; i < m; i++)
	{
		int x = abs(s[n][m] - 2 * s[n][i]);
		ans = min(ans, x);
	}
	cout << ans;
}
int main()
{
	cin >> n >> m;
	solve();
	return 0;
}