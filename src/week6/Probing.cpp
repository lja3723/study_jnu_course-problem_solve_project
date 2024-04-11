//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

namespace week6_Probing {

	int getLuckyNumber(vector<bool>& pool, int N, int id) {
		int seed = id % N; //id�� �̿��� ������ �õ带 ����

		//�õ忡 �ش��ϴ� ��÷�� ��ȣ�� �߱��� �Ǿ��ִ� ���
		//�õ�� �ش��ϴ� ��÷�� ��ȣ�� �߱��̾� �� ������ ������ ���� �ݺ��Ѵ�.
		while (pool[seed]) {
			//�õ带 1 ���� ��Ŵ
			//���� 1 ������ ���� N�̶�� N���� ���� �������� ����
			//seed�� 0���� ���ư����� ��
			seed = (seed + 1) % N;
		}

		pool[seed] = true; //�õ忡 �ش��ϴ� ��÷�� ��ȣ�� �߱޵Ǿ����Ƿ� �߱޵Ǿ��ٰ� üũ
		return seed;
	}

	int main() {
		int N, M; cin >> N >> M; //N, M �Է� �ޱ�

		//N���� ���� ��ȣ ���� ���� �迭 ����
		vector<bool> luckyNumberPool(N, false);

		for (int m = 0; m < M; m++) {
			int id; cin >> id; //ȸ����ȣ �Է¹ޱ�

			//�ش� ȸ���� ȸ���� ��ȣ ���
			cout << getLuckyNumber(luckyNumberPool, N, id) << endl;
		}

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
//int main() { return week6_Probing::main(); }

/*
	>> input
5000 5
2878
15092880
1
18762879
77787879
	<< output
2878
2880
1
2879
2881
*/