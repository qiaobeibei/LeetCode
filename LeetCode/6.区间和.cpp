//#include <iostream>
//#include <vector>
//
//	/*
//给定一个整数数组 array，请计算该数组在每个指定区间内元素的总和。
//
//输入：第一行输入为整数数组 array 的长度 n，接下来 n 行，每行一个整数，表示数组的元素。
//随后的输入为需要计算总和的区间下标：a，b （b > = a），直至文件结束。
//
//输出：输出每个指定区间内元素的总和。
//*/
//
///*
//前缀和的思想是重复利用计算过的子数组之和，从而降低区间查询需要累加计算的次数。
//
//前缀和 在涉及计算区间和的问题时非常有用！
//
//前缀和的思路其实很简单，我给大家举个例子很容易就懂了。
//
//例如，我们要统计 vec[i] 这个数组上的区间和。
//
//我们先做累加，即 p[i] 表示 下标 0 到 i 的 vec[i] 累加 之和。
//
//我们想统计，在vec数组上 下标 2 到下标 5 之间的累加和，那是不是就用 p[5] - p[1] 就可以了。
//*/
//
//// 前缀和
//int main() {
//	using std::cin;
//	using std::cout;
//	using std::vector;
//
//	int numl;
//	cin >> numl;		
//	vector<int>* vec = new vector<int>(numl, 0);
//	vector<int>* p = new vector<int>(numl, 0);
//
//	for (int i = 0, presum = 0; i < numl; i++) {
//		// 这里不可以用vec + 1当vec[i]，vec是std::vector<int>* 类型的指针，将vec+1其实是访问vec之后的内存；
//		// 要访问和修改 std::vector<int> 的元素，需要先解引用指针 array 来得到实际的 vector 对象，
//		// 然后使用 [] 操作符或者 at() 方法来访问向量的元素。
//		cin >> (*vec)[i];		
//		// 消耗多余符号
//		while (cin and cin.get() != '\n')
//			continue;
//		// 得到一个从下标0到i的累计和，并记录在p容器中
//		presum += (*vec)[i];
//		(*p)[i] = presum;
//	}
//
//	int a, b;
//	while (cin >> a >> b) {
//		int sum = 0;
//		if (a == 0) sum = (*p)[b];
//		// (*p)[b] - (*p)[a - 1]其实就是求容器vec在区间[a,b]内的元素和
//		else sum = (*p)[b] - (*p)[a - 1];
//		cout << sum << std::endl;
//	}
//
//	delete vec, p;
//
//	return 0;
//}
//
//
////暴力解法，耗时严重
//int main() {
//	using std::cin;
//	using std::cout;
//	using std::vector;
//
//	int numl;
//	cin >> numl;
//	vector<int>* array = new vector<int>(numl, 0);
//	for (int i = 0; i < numl; i++) {
//		cin >> (*array)[i];
//		while (cin and cin.get() != '\n')
//			continue;
//	}
//
//	int a, b;
//	while (cin >> a >> b) {
//		int sum = 0;
//		for (a; a <= b; a++)
//			sum += (*array)[a];
//		cout << sum << std::endl;
//	}
//
//	delete array;
//
//	return 0;
//}
//
