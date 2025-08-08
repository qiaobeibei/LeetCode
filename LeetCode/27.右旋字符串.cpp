/*
字符串的右旋转操作是把字符串尾部的若干个字符转移到字符串的前面。给定一个字符串 s 和一个正整数 k，
请编写一个函数，将字符串中的后面 k 个字符移到字符串的前面，实现字符串的右旋转操作。

例如，对于输入字符串 "abcdefg" 和整数 2，函数应该将其转换为 "fgabcde"。
*/

#include <iostream>
#include <string>

using std::string;
void reverse(string& s, int start, int end);


int main() {
	string s;
	int k;
	while (std::cin >> k >> s) {
		reverse(s, 0, s.size() - 1);
		reverse(s, 0, k - 1);
		reverse(s, k, s.size() - 1);
		std::cout << s;
	}

	return 0;
}

void reverse(string& s, int start, int end) {
	for (int i = start, j = end; i < j; i++, j--) {
		std::swap(s[i], s[j]);
	}
}