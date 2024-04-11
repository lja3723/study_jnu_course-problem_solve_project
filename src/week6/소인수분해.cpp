//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>

using namespace std;

namespace week6_factorization {

	void testCase(int tIdx) {
		int n; cin >> n; //���μ������� ���� n �Է�
		int tmpN = n; //n�� �����ϴ� �ӽ� n
		int p = 2; //���� ��, ó������ 2�� ����

		//tIdx ��° �׽�Ʈ���̽���� �ǹ�
		cout << "#" << tIdx << ":\n";

		//���� ���� �������� n ������ ���� �ݺ��Ѵ�.
		while (p * p <= n) {

			//p�� ���μ��̹Ƿ�
			if (tmpN % p == 0) {
				cout << p << " "; //����� ��
				tmpN /= p; //�ӽ� n�� P�� ������.
			}
			//p�� ���μ��� �ƴϹǷ�
			else {
				p++; //p�� ������Ų��.
			}
		}

		//�ӽ� n�� 1�� �ƴ϶�� ���μ� ���ذ� ������ �Ϸ�� ���� �ƴϴ�.
		//tmpN�� ����� ���� �� N�� ������ ���μ�(�Ҽ�)��� �ǹ��̹Ƿ�,
		//�� ���� ����Ѵ�.
		if (tmpN != 1) 
			cout << tmpN;

		//���μ� ���ذ� �Ϸ�Ǿ����Ƿ�, ������ ��Ų��.
		cout << "\n";
	}

	int main() {
		int T; cin >> T; //�׽�Ʈ���̽� Ƚ�� �Է�

		//�� �׽�Ʈ�� Tȸ �ݺ�
		for (int t = 1; t <= T; t++)
			testCase(t);

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
//int main() { return week6_factorization::main(); }

/*
	>> input
3
24
28
21
	<< output
#1:
2 2 2 3
#2:
2 2 7
#3:
3 7
*/