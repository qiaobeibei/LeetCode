//#include <iostream>
//#include <vector>
//
//	/*
//����һ���������� array��������������ÿ��ָ��������Ԫ�ص��ܺ͡�
//
//���룺��һ������Ϊ�������� array �ĳ��� n�������� n �У�ÿ��һ����������ʾ�����Ԫ�ء�
//��������Ϊ��Ҫ�����ܺ͵������±꣺a��b ��b > = a����ֱ���ļ�������
//
//��������ÿ��ָ��������Ԫ�ص��ܺ͡�
//*/
//
///*
//ǰ׺�͵�˼�����ظ����ü������������֮�ͣ��Ӷ����������ѯ��Ҫ�ۼӼ���Ĵ�����
//
//ǰ׺�� ���漰��������͵�����ʱ�ǳ����ã�
//
//ǰ׺�͵�˼·��ʵ�ܼ򵥣��Ҹ���Ҿٸ����Ӻ����׾Ͷ��ˡ�
//
//���磬����Ҫͳ�� vec[i] ��������ϵ�����͡�
//
//���������ۼӣ��� p[i] ��ʾ �±� 0 �� i �� vec[i] �ۼ� ֮�͡�
//
//������ͳ�ƣ���vec������ �±� 2 ���±� 5 ֮����ۼӺͣ����ǲ��Ǿ��� p[5] - p[1] �Ϳ����ˡ�
//*/
//
//// ǰ׺��
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
//		// ���ﲻ������vec + 1��vec[i]��vec��std::vector<int>* ���͵�ָ�룬��vec+1��ʵ�Ƿ���vec֮����ڴ棻
//		// Ҫ���ʺ��޸� std::vector<int> ��Ԫ�أ���Ҫ�Ƚ�����ָ�� array ���õ�ʵ�ʵ� vector ����
//		// Ȼ��ʹ�� [] ���������� at() ����������������Ԫ�ء�
//		cin >> (*vec)[i];		
//		// ���Ķ������
//		while (cin and cin.get() != '\n')
//			continue;
//		// �õ�һ�����±�0��i���ۼƺͣ�����¼��p������
//		presum += (*vec)[i];
//		(*p)[i] = presum;
//	}
//
//	int a, b;
//	while (cin >> a >> b) {
//		int sum = 0;
//		if (a == 0) sum = (*p)[b];
//		// (*p)[b] - (*p)[a - 1]��ʵ����������vec������[a,b]�ڵ�Ԫ�غ�
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
////�����ⷨ����ʱ����
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
