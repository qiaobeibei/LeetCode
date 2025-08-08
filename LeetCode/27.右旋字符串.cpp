/*
�ַ���������ת�����ǰ��ַ���β�������ɸ��ַ�ת�Ƶ��ַ�����ǰ�档����һ���ַ��� s ��һ�������� k��
���дһ�����������ַ����еĺ��� k ���ַ��Ƶ��ַ�����ǰ�棬ʵ���ַ���������ת������

���磬���������ַ��� "abcdefg" ������ 2������Ӧ�ý���ת��Ϊ "fgabcde"��
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