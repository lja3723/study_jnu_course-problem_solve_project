//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>

using namespace std;

namespace week6_sudoku {

	void unitTest(int tcase) {
		int n; cin >> n; //1~81 ���� ���� �Է¹ޱ�

		int row = ((n - 1) / 9) + 1; //n�� ���° ������ ���
		int col = ((n - 1) % 9) + 1; //n�� ���° ������ ���
		int group = 3 * ((row - 1) / 3) + ((col - 1) / 3) + 1; //n�� �� ��° �׷����� ���

		//���� ��, ��, �׷� ���
		cout << "Case #" << tcase << ":";
		cout << row << " " << col << " " << group << endl;
 	}

	int main() {
		//�׽�Ʈ���̽� �� �Է� ���� ��, �׽�Ʈ���̽� �� ��ŭ �����׽�Ʈ�� �����Ѵ�.
		int T; cin >> T;
		for (int t = 1; t <= T; t++)
			unitTest(t);
		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
//int main() { return week6_sudoku::main(); }

/*
	>> input
5
1
2
3
4
5
	<< output
Case #1:
1 1 1
Case #2:
1 2 1
Case #3:
1 3 1
Case #4:
1 4 2
Case #5:
1 5 2
*/