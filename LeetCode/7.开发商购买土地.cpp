/*
在一个城市区域内，被划分成了n * m个连续的区块，每个区块都拥有不同的权值，代表着其土地价值。
目前，有两家开发公司，A 公司和 B 公司，希望购买这个城市区域的土地。

现在，需要将这个城市区域的所有区块分配给 A 公司和 B 公司。

然而，由于城市规划的限制，只允许将区域按横向或纵向划分成两个子区域，而且每个子区域都必须包
含一个或多个区块。 为了确保公平竞争，你需要找到一种分配方式，使得 A 公司和 B 公司各自的子
区域内的土地总价值之差最小。

注意：区块不可再分。

输入：
	第一行输入两个正整数，代表 n 和 m。
	接下来的 n 行，每行输出 m 个正整数。
输出：
	请输出一个整数，代表两个子区域内土地总价值之间的最小差距。

	1 <= n, m <= 100；
	n 和 m 不同时为 1。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// 前缀和
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
			(*row)[i] += (*vec)[i][j];						// 将矩阵vec每一行的元素之和存储至row
			(*col)[j] += (*vec)[i][j];						// 将矩阵vec每一列的元素之和存储至col
		}
		if (i > 0) (*row)[i] += (*row)[(long long)i - 1];	// 将row的元素变换为当前元素与前面元素之和（前缀和）
	}

	for (int j = 0; j < m; j++)
		if (j != 0)
			(*col)[j] += (*col)[(long long)j - 1];			// 将col的元素变换为当前元素与前面元素之和（前缀和）


	int result_row = INT_MAX;
	for (int i = 0; i < n - 1; i++)
		// 求解矩阵划分为两部分后，两部分差的最小值
		result_row = std::min(std::abs((*row)[i] - ((*row)[(long long)n - 1] - (*row)[i])), result_row);

	int result_col = INT_MAX;
	for (int j = 0; j < m - 1; j++)
		result_col = std::min(std::abs((*col)[j] - ((*col)[(long long)m - 1] - (*col)[j])), result_col);

	// 返回分别以行和列为导向，两部分差的最小值
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