///*
//��һ�����������ڣ������ֳ���n * m�����������飬ÿ�����鶼ӵ�в�ͬ��Ȩֵ�������������ؼ�ֵ��
//Ŀǰ�������ҿ�����˾��A ��˾�� B ��˾��ϣ���������������������ء�
//
//���ڣ���Ҫ�������������������������� A ��˾�� B ��˾��
//
//Ȼ�������ڳ��й滮�����ƣ�ֻ�������򰴺�������򻮷ֳ����������򣬶���ÿ�������򶼱����
//��һ���������顣 Ϊ��ȷ����ƽ����������Ҫ�ҵ�һ�ַ��䷽ʽ��ʹ�� A ��˾�� B ��˾���Ե���
//�����ڵ������ܼ�ֵ֮����С��
//
//ע�⣺���鲻���ٷ֡�
//
//���룺
//	��һ���������������������� n �� m��
//	�������� n �У�ÿ����� m ����������
//�����
//	�����һ�����������������������������ܼ�ֵ֮�����С��ࡣ
//
//	1 <= n, m <= 100��
//	n �� m ��ͬʱΪ 1��
//*/
//
//
///*
//* �� C++ �У�����ȫ�ֱ��������κκ���֮�ⶨ��ı������;�̬�ֲ����������Զ���ʼ��Ϊ�㡣
//����άǰ׺�͡�
//���ڸ����Ķ�ά����A,���ǹ���һ����ά����s,����s[i][j]��ʾ�Ӿ�������Ͻ�(1,1)��λ��(i-1,j-1)������Ԫ�صĺ͡�
//ע�⣺1)�����ѭ������Ҫ��1��ʼ����Ϊ��0��ʼѭ�����ᵼ��s[-1][0]��s[-1][-1]��s[0][-1]�ĳ��֣������ڴ�й¶
//	  2)�����СΪ��n+1��*��m+1��������ᵼ�����һλ���ִ洢����ȥ������Խ��
//���㹫ʽ��s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
//����������s[i][j]=��ߵ������+�ϱߵ������-�ظ�����������+��ǰԪ�ص�ֵ
//
//������һ��3*3�ľ���
//		1 2 3
//		4 5 6
//		7 8 9
//	s[1][1] = s[0][1] + s[1][0] - s[0][0] + A[1][1] = 1
//	s[1][2] = s[0][2] + s[1][1] - s[0][1] + A[1][2] = 3
//	s[2][2] = s[1][2] + s[2][1] - s[1][1] + A[2][2] = 11
//*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <climits>
//
//// ��άǰ׺�ͣ����ã�
//int main() {
//	using std::vector;
//	using std::cin;
//	using std::cout;
//
//	int n, m, temp;											// temp������ʱ�洢����Ԫ�ص�ֵ
//	cin >> n >> m;
//	// �����άǰ׺�;���
//	vector<vector<int>>* vec = new vector<vector<int>>((long long)n + 1, vector<int>((long long)m + 1, 0));
//
//	// ��¼��������ǰ׺��
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++) {
//			cin >> temp;
//			// ǰ׺�;���
//			(*vec)[i][j] = (*vec)[(long long)i - 1][j] + (*vec)[i][(long long)j - 1]
//				- (*vec)[(long long)i - 1][(long long)j - 1] + temp;
//		}
//
//	int ans = INT_MAX;
//	// ˮƽ�ָ�
//	for (int i = 1; i < n; i++) {
//		int subX = (*vec)[n][m] - 2 * (*vec)[i][m];
//		ans = std::min(std::abs(subX), ans);
//	}
//	// ��ֱ�ָ�
//	for (int j = 1; j < m; j++) {
//		int subY = (*vec)[n][m] - 2 * (*vec)[n][j];
//		ans = std::min(std::abs(subY), ans);
//	}
//
//	cout << ans;
//
//	delete vec;
//}
//
//
//// һάǰ׺��(�ֱ�����������洢��ά�����к��е�Ԫ�غ�)
//int main() {
//	using std::vector;
//	using std::cin;
//	using std::cout;
//
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>>* vec = new vector<vector<int>>(n, vector<int>(m, 0));
//	vector<int>* row = new vector<int>(n, 0);
//	vector<int>* col = new vector<int>(m, 0);
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> (*vec)[i][j];
//			(*row)[i] += (*vec)[i][j];						// ������vecÿһ�е�Ԫ��֮�ʹ洢��row
//			(*col)[j] += (*vec)[i][j];						// ������vecÿһ�е�Ԫ��֮�ʹ洢��col
//		}
//		if (i > 0) (*row)[i] += (*row)[(long long)i - 1];	// ��row��Ԫ�ر任Ϊ��ǰԪ����ǰ��Ԫ��֮�ͣ�ǰ׺�ͣ�
//	}
//
//	for (int j = 0; j < m; j++)
//		if (j != 0)
//			(*col)[j] += (*col)[(long long)j - 1];			// ��col��Ԫ�ر任Ϊ��ǰԪ����ǰ��Ԫ��֮�ͣ�ǰ׺�ͣ�
//
//	// ǰ׺����ⷽ��
//	int result_row = INT_MAX;
//	for (int i = 0; i < n - 1; i++)
//		// �����󻮷�Ϊ�����ֺ������ֲ����Сֵ
//		result_row = std::min(std::abs((*row)[i] - ((*row)[(long long)n - 1] - (*row)[i])), result_row);
//
//	int result_col = INT_MAX;
//	for (int j = 0; j < m - 1; j++)
//		result_col = std::min(std::abs((*col)[j] - ((*col)[(long long)m - 1] - (*col)[j])), result_col);
//
//	// ���طֱ����к���Ϊ���������ֲ����Сֵ
//	cout << std::min(result_row, result_col);
//
//	delete vec, row, col;
//
//	return 0;
//}
//
