/*
����һ���ַ��� s��������Сд��ĸ�������ַ������дһ�����������ַ����е���ĸ�ַ����ֲ��䣬
����ÿ�������ַ��滻Ϊnumber�� ���磬���������ַ��� "a1b2c3"������Ӧ�ý���ת��Ϊ "anumberbnumbercnumber"��
*/

#include <iostream>
#include <string>

// ˫ָ�뷨
int main() {
	std::string instr;
	while (std::cin >> instr) {
		int OldIndex = instr.size() - 1;
		int count = 0;
		for (int i = 0; i < instr.size(); i++) { // ͳ�����ִ�С
			if (instr[i] >= '0' and instr[i] <= '9') {
				count++;
			}
		}
		// �����ַ���s�Ĵ�С��Ҳ���ǽ�ÿ�������滻��"number"֮��Ĵ�С
		instr.resize(instr.size() + count * 5);
		int NewIndex = instr.size() - 1;
		// �Ӻ���ǰ�������滻Ϊ"number"
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