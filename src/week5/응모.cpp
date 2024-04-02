//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

namespace week5_application {

	//�ø���ѹ��� �ִ�
	#define SERIAL_MAX 100000

	//�ø���ѹ��� ���� �󵵼��� ���ϴ� �迭
	vector<int> serial_freq(SERIAL_MAX + 1);

	int main() {
		int N; cin >> N; //�������� �� �Է�
		
		//�����͸� �Է¹ް�, �ø���ѹ��� �󵵼��� �����Ѵ�.
		while (N--) {
			int serial; cin >> serial; //�ø��� �ѹ� �Է¹ޱ�

			//�ش� �ø���ѹ��� �󵵼��� 1 �����Ѵ�.
			serial_freq[serial]++;
		}
		
		//������ ������ ��Ŀ� �°� ����Ѵ�.
		for (int serial = 1; serial <= SERIAL_MAX; serial++) {
			if (serial_freq[serial] == 1) //�� �ѹ��� ������ �ø��� ��ȣ�鸸 ������� ����Ѵ�.
				cout << serial << " ";
		}

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
//int main() { return week5_application::main(); }

/*
	>> input
6
2 3 3 4 7 5
	<< output
2 4 5 7
*/