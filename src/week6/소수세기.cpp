//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

namespace week6_counting_prime_numbers {

	//�������� ���� ������ �ִ� ������ ����
	const int RANGE_MAX = 1'000'000;

	//������ ���θ� �����ϴ� �迭.
	// isPrime[n] �� ���̸� n�� �Ҽ�, �ƴϸ� �Ҽ��� �ƴ�
	//�ʱ�ġ�� ��� ���� �Ҽ�(true)��� ����
	vector<bool> isPrime(RANGE_MAX + 1, true);
	
	//�����佺�׳׽��� ü �˰����� �̿��� isPrime ���͸� �ʱ�ȭ�ϴ� �Լ�
	void init_using_sieve_of_Eratosthenes() {
		isPrime[1] = false; //1�� �Ҽ��� �ƴϹǷ� �����Ѵ�.

		//p�� �������� RANGE_MAX�� ������ ���� �ݺ��Ѵ�.
		for (int p = 2; p * p <= RANGE_MAX; p++) {
			if (!isPrime[p]) //p�� �Ҽ���� ���� p�� Ž���ϱ� ���� �ǳʶڴ�.
				continue;

			//p�� �Ҽ��̹Ƿ�, 2 * p���� ������ p�� ����� RANGE_MAX���� ���
			//�Ҽ��� �ƴ϶�� üũ�Ѵ�.
			for (int i = 2 * p; i <= RANGE_MAX; i += p) {
				isPrime[i] = false;
			}
		}
	}

	int main() {
		//����Ǯ�� ��, �Ҽ� ����� �����佺�׳׽��� ü�� �̿��� �ʱ�ȭ�Ѵ�.
		init_using_sieve_of_Eratosthenes();

		//�׽�Ʈ���̽��� �Է¹޴´�.
		int T; cin >> T;

		//�׽�Ʈ���̽� Ƚ����ŭ �����Ѵ�.
		for (int t = 1; t <= T; t++) {
			int L, R; cin >> L >> R; //�Ҽ� ������ �� ���� L, R�� �Է¹޴´�.
			int count = 0; //�Ҽ� ������ ������ ������ �����Ѵ�.

			//L���� ������ R���� �� ������ k�� 1�� ������Ų��.
			for (int k = L; k <= R; k++)
				if (isPrime[k]) //k�� �Ҽ��� ������ 1 ������Ų��.
					count++;

			//�׽�Ʈ���̽��� ���� ������ ����Ѵ�.
			cout << "Case #" << t << ":\n";
			cout << count << endl;
		}

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
//int main() { return week6_counting_prime_numbers::main(); }

/*
	>> input
3
2 10
50 100
100 1000
	<< output
Case #1:
4
Case #2:
10
Case #3:
143

	>> input
10
1 1000000
1 1000000
1 1000000
1 1000000
1 1000000
1 1000000
1 1000000
1 1000000
1 1000000
1 1000000
	<< output
Case #1:
78498
Case #2:
78498
Case #3:
78498
Case #4:
78498
Case #5:
78498
Case #6:
78498
Case #7:
78498
Case #8:
78498
Case #9:
78498
Case #10:
78498
*/