//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

namespace week4_prime_number_determination {

	//����� 2������ �Ǵ��Ͽ�, N�� �Ҽ����� ���θ� ��ȯ�Ѵ�.
	bool isPrime(int N) {
		// 2 �̸��� ������ �Ҽ��� �ƴ�
		if (N < 2) return false;

		//�־��� N�� 1���� sqrt(N)���� �������� N�� �Ҽ����� �ƴ��� �Ǻ� ����
		//�̶� sqrt(10��)�� �뷫 32000�̹Ƿ�, �׽�Ʈ���̽��� �ִ� 10���̴���
		//2�� �ȿ� ��� ��쿡 ���� �Ǻ��� ������ ����

		//2���� ��谪���� N�� ���� �������� Ȯ����
		for (int n = 2; n*n <= N /* n <= sqrt(N) �� ���� ǥ��, ���� �������� ��Ȯ�� ��� */; n++)
			if (N % n == 0) return false; //������ �������� ���μ��� 2�� �ʰ��ߴٴ� �� -> �Ҽ��� �ƴ�
				

		//������������ ������ N �̸��� ���μ��� ���� == N�� �Ҽ���
		return true;
	}

	int main() {
		//�׽�Ʈ���̽� �� �Է�
		int T; cin >> T; 

		//�׽�Ʈ���̽� Tȸ ����
		for (int i = 1; i <= T; i++) {
			//�Ҽ� �Ǻ��� ���� �Է�
			int n; cin >> n; 
			//�׽�Ʈ���̽�
			cout << "Case #" << i << endl;
			//�Ҽ� ���ο� ���� ��� ���
			cout << (isPrime(n) ? "YES" : "NO") << endl;
		}

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�. (�ּ� ���� �� ����)
//int main() { return week4_prime_number_determination::main(); }

/*
	>> input
1
5
	<< output
Case #1
YES

	>> input
2
1
5
	<< output
Case #1
No
Case #2
YES
*/