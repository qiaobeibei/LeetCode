///*
//在一个城市区域内，被划分成了n * m个连续的区块，每个区块都拥有不同的权值，代表着其土地价值。
//目前，有两家开发公司，A 公司和 B 公司，希望购买这个城市区域的土地。
//
//现在，需要将这个城市区域的所有区块分配给 A 公司和 B 公司。
//
//然而，由于城市规划的限制，只允许将区域按横向或纵向划分成两个子区域，而且每个子区域都必须包
//含一个或多个区块。 为了确保公平竞争，你需要找到一种分配方式，使得 A 公司和 B 公司各自的子
//区域内的土地总价值之差最小。
//
//注意：区块不可再分。
//
//输入：
//	第一行输入两个正整数，代表 n 和 m。
//	接下来的 n 行，每行输出 m 个正整数。
//输出：
//	请输出一个整数，代表两个子区域内土地总价值之间的最小差距。
//
//	1 <= n, m <= 100；
//	n 和 m 不同时为 1。
//*/
//
//
///*
//* 在 C++ 中，所有全局变量（在任何函数之外定义的变量）和静态局部变量都会自动初始化为零。
//《二维前缀和》
//对于给定的二维矩阵A,我们构造一个二维数组s,其中s[i][j]表示从矩阵的左上角(1,1)到位置(i-1,j-1)的所有元素的和。
//注意：1)这里的循环必须要从1开始，因为从0开始循环，会导致s[-1][0]、s[-1][-1]、s[0][-1]的出现，出现内存泄露
//	  2)矩阵大小为（n+1）*（m+1），否则会导致最后一位数字存储不进去，数组越界
//计算公式：s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
//文字描述：s[i][j]=左边的区域和+上边的区域和-重复计算的区域和+当前元素的值
//
//假设有一个3*3的矩阵：
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
//// 二维前缀和（更好）
//int main() {
//	using std::vector;
//	using std::cin;
//	using std::cout;
//
//	int n, m, temp;											// temp用于暂时存储输入元素的值
//	cin >> n >> m;
//	// 定义二维前缀和矩阵
//	vector<vector<int>>* vec = new vector<vector<int>>((long long)n + 1, vector<int>((long long)m + 1, 0));
//
//	// 记录输入矩阵的前缀和
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++) {
//			cin >> temp;
//			// 前缀和矩阵
//			(*vec)[i][j] = (*vec)[(long long)i - 1][j] + (*vec)[i][(long long)j - 1]
//				- (*vec)[(long long)i - 1][(long long)j - 1] + temp;
//		}
//
//	int ans = INT_MAX;
//	// 水平分割
//	for (int i = 1; i < n; i++) {
//		int subX = (*vec)[n][m] - 2 * (*vec)[i][m];
//		ans = std::min(std::abs(subX), ans);
//	}
//	// 垂直分割
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
//// 一维前缀和(分别用两个数组存储二维矩阵行和列的元素和)
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
//			(*row)[i] += (*vec)[i][j];						// 将矩阵vec每一行的元素之和存储至row
//			(*col)[j] += (*vec)[i][j];						// 将矩阵vec每一列的元素之和存储至col
//		}
//		if (i > 0) (*row)[i] += (*row)[(long long)i - 1];	// 将row的元素变换为当前元素与前面元素之和（前缀和）
//	}
//
//	for (int j = 0; j < m; j++)
//		if (j != 0)
//			(*col)[j] += (*col)[(long long)j - 1];			// 将col的元素变换为当前元素与前面元素之和（前缀和）
//
//	// 前缀和求解方法
//	int result_row = INT_MAX;
//	for (int i = 0; i < n - 1; i++)
//		// 求解矩阵划分为两部分后，两部分差的最小值
//		result_row = std::min(std::abs((*row)[i] - ((*row)[(long long)n - 1] - (*row)[i])), result_row);
//
//	int result_col = INT_MAX;
//	for (int j = 0; j < m - 1; j++)
//		result_col = std::min(std::abs((*col)[j] - ((*col)[(long long)m - 1] - (*col)[j])), result_col);
//
//	// 返回分别以行和列为导向，两部分差的最小值
//	cout << std::min(result_row, result_col);
//
//	delete vec, row, col;
//
//	return 0;
//}
//
