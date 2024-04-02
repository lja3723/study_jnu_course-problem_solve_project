//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>

using namespace std;

namespace week5_paint {

	//�¼��� �ִ� ��
	#define SEAT_MAX 1000

	//�¼��� ���� �����ϴ� �迭
	//�������� ���� ������ �ִ� ������ ũ��(1000)�� �����Ѵ�.
	//�� �� �¼��� ������ 1���� �����ϹǷ�, 0��° �ε����� ���̷� ����ϱ� ����
	//�ִ� + 1 ��ŭ�� �迭 ũ�⸦ �����Ѵ�.
	//�׷��� �迭�� �ε����� �� �¼��� ��ȣ�� ��ġ�ϰ� �ȴ�.
	int seat[SEAT_MAX + 1]; //���� �����̹Ƿ� 0���� �ʱ�ȭ�ȴ�.

	//������ �ִ� ������
	#define COLOR_MAX 100

	//������ �󵵼��� �����ϴ� �迭
	int color_freq[COLOR_MAX];

	int main() {
		//�¼��� ���� ��ĥ�� ��� ���� �Է¹���
		int N, M; cin >> N >> M; 

		//M���� ������� �¼��� ��ĥ�� ������.
		while (M--) {
			//��ĥ ������ ������ �Է¹޴´�.
			int left, right, color;
			cin >> left >> right >> color;

			//������ ������ �������� �¼��� ĥ�Ѵ�.
			for (int c = left; c <= right; c++)
				seat[c] = color;
		}

		//������ �� �󵵼��� ���Ѵ�.
		for (int i = 1; i <= N; i++) {
			int color = seat[i]; //i��° �¼��� ����
			color_freq[color]++; //�ش� ������ �󵵼��� 1 ������Ų��.
		}


		//���� ����� ������ ����� ���� ���� ������ ������ ���Ѵ�.
		//�� ������ �켱 ù ��° �¼��� ������ �ʱ�ȭ�Ѵ�.
		int max_freq_color = seat[1]; //���� ����� ������ ����
		int min_freq_color = seat[1]; //���� ���� ������ ����
		for (int i = 0; i < COLOR_MAX; i++) {
			//� �¼����� ĥ������ ���� �����̶�� ��� ����� �ƴϹǷ� �����Ѵ�.
			if (color_freq[i] == 0)
				continue;

			//���� ����� ���� ����, ���� ���� ���� ���� ���� ���Ѵ�.
			if (color_freq[i] > color_freq[max_freq_color])
				max_freq_color = i;
			if (color_freq[i] < color_freq[min_freq_color])
				min_freq_color = i;
		}

		//������ ������ ��Ŀ� �°� ����Ѵ�.
		cout << max_freq_color << endl << min_freq_color;

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
//int main() { return week5_paint::main(); }

/*
	>> input
10 2
2 5 1
4 7 2
	<< output
0
1

	>> input
10 2
1 9 5
2 10 5
	<< output
5
5
*/