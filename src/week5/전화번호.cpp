//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>

using namespace std;

namespace week5_tel_number {

	//��ȭ��ȣ�� �Ѱ� �ٿ���� (10000 �̸��̾�� ��)
	#define NUM_MAX 10000

	// �� ��ȭ��ȣ 0000~9999 ������ ���� �󵵼�(frequency)�� ī������ �迭
	// 10000���� ��ȭ��ȣ�� ���� �󵵸� ī��Ʈ�ϹǷ�, ���̰� 10000�� �迭 ���� �ʿ�
	int telnum_freq[NUM_MAX] = { 0 }; // �迭�� ��� 0���� �ʱ�ȭ

	int main() {
		int N; cin >> N; //��ȭ��ȣ �� N �Է� �ޱ�

		for (int i = 0; i < N; i++) {
			int num; cin >> num; //��ȭ��ȣ ���ڸ� �Է� �ޱ�

			// �ε����� ��ȭ��ȣ ���ڸ��� �迭 ������ ����
			// �̷��� �ϸ� �Է¹��� ��ȭ��ȣ�� �� �� �����ߴ��� ī������ ����
			telnum_freq[num]++; 
		}

		// ���� ���� �󵵼��� ���� ��ȭ��ȣ ���� ����
		int max_telnum = 0; //�� ���� ��ȭ��ȣ�� �ʱ�ġ ����

		//�󵵼� �迭�� Ž���ϸ鼭 ���� �󵵰� ū ��ȭ��ȣ�� Ž���� ����
		for (int i = 0; i < NUM_MAX; i++)
			if (telnum_freq[i] > telnum_freq[max_telnum])
				max_telnum = i;

		//ã�� ������ ���� ���Ŀ� �°� ���
		printf("%04d", max_telnum);

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
//int main() { return week5_tel_number::main(); }

/*
	>> input
3
1234
4321
1234
	<< output
1234

	>> input
2
4321
1234
	<< output
1234
*/