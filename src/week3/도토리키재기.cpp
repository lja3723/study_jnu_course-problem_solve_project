//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

namespace week3_measureHeight {

	int getTallest(int N, int M, vector<int>& height, vector<int>& month) {
		int tallest = -1; //���� ū ���丮 Ű�� -1�� �ʱ�ȭ (������ M���� ���丮 ���� ��� �״�� ����)

		for (int i = N - 1; i >= 0; i--) { //���� �ڿ������� Ž����
			if (month[i] == M) return height[i]; //������ M���� ��� �� ���� ���� ū Ű�̹Ƿ� ��ȯ
		}

		return tallest;
	}

	int main() {
		int N;
		cin >> N;

		vector<int> height(N), month(N);
		for (int i = 0; i < N; i++)
			cin >> height[i]; //Ű �迭 �Է¹��
		for (int i = 0; i < N; i++)
			cin >> month[i]; //�� �迭 �Է¹��

		int M;
		cin >> M;

		cout << getTallest(N, M, height, month);

		return 0;
	}

}

//int main() { week3_measureHeight::main(); }

/*
	>> input
5
12 13 14 15 16
1 5 7 2 3
2
	<< output
15

	>> input
5
12 13 14 15 16
1 5 7 2 3
12
	<< output
-1

	>> input
20
10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
1 11 8 10 7 11 8 12 8 6 2 10 10 1 3 12 3 5 5 5
1
	<< output
23
*/