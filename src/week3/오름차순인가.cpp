//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

namespace week3_isAscent {

	bool isAscentOrdered(int N, vector<int>& student) {

		//i = 1���� ���������μ� �迭 ���̰� 1�� ��� �׻� ���� ��µǵ��� �� �� ����
		//	���̰� 1�� �迭�� �׻� ���������̶�� �� �� ����
		for (int i = 1; i < N; i++)
			//���������� �����ϴ� ����̹Ƿ�, false ���
			if (student[i - 1] > student[i]) return false;
	
		return true;
	}

	int main() {
		int N;
		cin >> N;
		vector<int> student(N);
		for (int i = 0; i < N; i++)
			cin >> student[i];

		//���������̸� YES, �ƴϸ� NO ���
		printf(isAscentOrdered(N, student) ? "YES" : "NO");

		return 0;
	}

}

//int main() { week3_isAscent::main(); }

/*
	>> input
5
1 2 3 5 4
	<< output
NO
*/