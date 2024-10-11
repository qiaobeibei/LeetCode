/*
给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，
而将每个数字字符替换为number。 例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。
*/

#include <iostream>
#include <string>

// 双指针法
int main() {
	std::string instr;
	while (std::cin >> instr) {
		int OldIndex = instr.size() - 1;
		int count = 0;
		for (int i = 0; i < instr.size(); i++) { // 统计数字大小
			if (instr[i] >= '0' and instr[i] <= '9') {
				count++;
			}
		}
		// 扩充字符串s的大小，也就是将每个数字替换成"number"之后的大小
		instr.resize(instr.size() + count * 5);
		int NewIndex = instr.size() - 1;
		// 从后往前将数字替换为"number"
		while (OldIndex >= 0) {
			if (instr[OldIndex] >= '0' and instr[OldIndex] <= '9') {
				instr[NewIndex--] = 'r';
				instr[NewIndex--] = 'e';
				instr[NewIndex--] = 'b';
				instr[NewIndex--] = 'm';
				instr[NewIndex--] = 'u';
				instr[NewIndex--] = 'n';
			}
			else {
				instr[NewIndex--] = instr[OldIndex];
			}
			OldIndex--;
		}
		std::cout << instr << std::endl;
	}
	return 0;
}