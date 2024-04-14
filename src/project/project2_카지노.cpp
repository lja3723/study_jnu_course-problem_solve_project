//����Ʈ������а� 201986 �����

#include <iostream>
#include <vector>
#include <functional>
#include <time.h>

using namespace std;

namespace jnu_project2_casino {

	//5���� ī�� ����Ʈ�� ǥ���ϴ� Ŭ����
	class CardList {
	private:
		vector<int> list; //5���� ī�� ����Ʈ

		//�־��� 5���� ī�� ����Ʈ(list)������ costMax�� ����Ѵ�.
		int calculateCostMax() const {
			int costMax = 0;

			//5�� �߿��� 3���� �̴� ��� ����� ���� Ž���ϸ鼭,
			for (int i = 0; i < 3; i++)
				for (int j = i + 1; j < 4; j++)
					for (int k = j + 1; k < 5; k++)
						// �� �߿��� ���� 1�� �ڸ� ���� �ִ밡 �Ǵ� ��츦 ����Ѵ�.
						costMax = max(costMax, (list[i] + list[j] + list[k]) % 10);

			return costMax;
		}

	public:
		CardList() : list(5, 0) {} //���� �� ���̰� 5�̰� ���Ұ� 0�� vector�� �ʱ�ȭ�Ѵ�.
		int& operator[](int index) { return list[index]; } //operator[]�� �����ε����� ÷�� ������ ����Ѵ�.
		const int getCostMax() const { return calculateCostMax(); }; //5�� ����Ʈ������ costMax�� ��ȯ�Ѵ�.
	};


	//�־��� �۾��� ����ð��� �����ϴ� Ŭ�����̴�.
	class ProcessingTimeMeter {
	private:
		function<void(void)> process; //�ð��� ������ �۾�
	public:
		ProcessingTimeMeter(function<void(void)> process) : process(process) {}

		double measureTime() {
			clock_t duration = -clock(); //�۾��ð� ���� ����
			process(); //�۾��� �����Ѵ�.
			duration += clock(); //�۾��ð� ���� ����

			return (double)duration / CLOCKS_PER_SEC; //������ �۾��ð�(ms)�� �����Ѵ�.
		}
	};


	//stdin�������� ������ �����͸� �Է¹޴´�.
	void inputDataFromStdin(int& N, vector<CardList>& cardLists) {
		cin >> N; //���� �ο��� �Է¹���

		//�� �����ο����� �־��� 5���� ī�� ����Ʈ�� �Է¹���
		for (int n = 1; n <= N; n++) {
			//n�� �����ڿ��� �־��� ī�� ����Ʈ�� �Է� �޴´�.
			for (int i = 0; i < 5; i++)
				cin >> cardLists[n][i];
		}
	}


	//�����ں� costMax�� ��� �迭�� �ʱ�ȭ�Ѵ�.
	void initCostMaxVector(const int& N, const vector<CardList>& cardLists, vector<int>& costMax) {
		for (int n = 1; n <= N; n++)
			costMax[n] = cardLists[n].getCostMax(); //n�� �������� ī�帮��Ʈ���� costMax�� �޾ƿ� ��, �� ������ costMax�� �����Ѵ�.
	}


	//costMax �迭�� �̿��Ͽ� ���� ���� �ڸ��� ���� ū �������� ��ȣ�� ��ȯ�Ѵ�.
	//�� �׷��� �����ڰ� ���� ���� ���, ������ ��ȣ�� ū ���� �����Ѵ�.
	int getMaximumParticipant(const int& N, const vector<int>& costMax) {
		int maximum = N;

		//�迭�� �ڿ������� Ž���Ѵ�.
		for (int n = N - 1; n >= 0; n--) {

			//���� ū ���� �߰��� ���, �� ������ �����Ѵ�.
			if (costMax[n] > costMax[maximum])
				maximum = n;
		}

		return maximum; //���� ���� �ڸ��� ���� ū �������� ��ȣ�� ��ȯ
	}


	int main() {
		//�������� �־��� �� �ִ� ���� �ο��� �ִ��̴�.
		const int PopulationMax = 1'000;
		
		int N; //���� �ο��̴�.

		//�� �迭�� ������ ���ҿ��� ������ ���� ����ȴ�:
		//	"�־��� 5���� ī�� �� 3���� ���� ��� ����� ���� Ȯ������ ��,
		//	�� ����� �� �� ī�� 3���� ���� 1�� �ڸ� ���� ���� ũ�� �Ǵ� �ִ�"
		// 
		//�� ���� �̸��� "costMax"��� �̸� ������. �� ��, costMax[n]�� �ǹ��ϴ� ���� ������ ����:
		//	n�� �����ڿ��� �־��� 5�� ī��� ���� �� �ִ� costMax
		//	��, n��° �����ڰ� ���� �� �ִ� ���� ū ���̴�.
		vector<int> costMax(PopulationMax + 1);

		//�� �迭�� ���Ҵ� "���� ������ int�̰� ���̰� 5�� �迭"�̰�,
		//cardLists[n]�� �ǹ��ϴ� ���� ������ ����:
		//	n�� �����ڿ��� �־��� 5���� ī���� ���
		vector<CardList> cardLists(PopulationMax + 1);

		//stdin�������� ������ �����͸� �Է¹޴´�.
		//�� �۾��� �ð� ������ ���� �ʴ´�.
		inputDataFromStdin(N, cardLists);

		//�ð��� ������ �۾��� �����Ѵ�.
		ProcessingTimeMeter meter([&N, &cardLists, &costMax] {
			//�����ں� costMax�� ��� �迭�� �ʱ�ȭ�Ѵ�.
			initCostMaxVector(N, cardLists, costMax);	

			//costMax �迭�� �̿��Ͽ� ���� ���� �ڸ��� ���� ū �������� ��ȣ�� ����� ��, �� ���� ����Ѵ�.
			cout << getMaximumParticipant(N, costMax) << endl;
		});

		//�۾��� ���� �ð��� ������ ��, ���� �ð��� ����Ѵ�.
		printf("%����ð�: %.3lf��\n", meter.measureTime());
		
		return 0;
	}
}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
//int main() { return jnu_project2_casino::main(); }


/*
	>> input
3
9 5 4 5 7
1 1 1 1 1
10 3 2 3 2
	<< output
1
����ð�: xxx��

	>> input
2
1 1 1 1 1
1 1 1 1 1
	<< output
2
����ð�: xxx��

	>> input
3
9 5 4 5 7
1 1 1 1 1
10 3 2 3 2
	<< output
1
����ð�: xxx��

	>> input
100
8 1 7 3 8
7 3 10 7 9
2 5 3 7 7
10 2 8 4 5
10 4 8 9 5
2 1 6 9 1
6 10 10 2 7
1 10 7 9 5
7 4 8 10 4
7 10 4 9 6
5 2 6 2 10
3 1 5 6 9
1 1 9 7 7
9 2 9 4 2
7 6 1 2 2
9 2 10 3 10
4 5 1 3 3
10 1 4 2 10
9 7 5 2 1
7 9 7 8 8
2 6 8 10 7
7 6 9 4 3
1 1 9 4 7
1 2 1 1 7
3 10 1 1 7
3 8 9 5 7
6 5 6 10 8
9 10 10 10 9
5 10 9 8 3
8 8 2 5 3
4 10 4 6 4
9 6 9 10 4
2 5 1 10 10
3 10 10 3 5
3 6 1 3 2
9 7 7 8 1
8 5 5 2 8
2 5 1 3 2
2 9 10 8 5
5 8 10 6 6
6 6 4 4 2
7 5 6 4 5
4 3 7 4 2
8 5 10 5 8
4 4 3 8 1
8 4 7 4 10
1 10 5 1 3
4 2 2 8 8
7 10 4 2 1
9 7 10 1 2
1 10 1 6 4
8 2 2 9 3
2 1 5 7 3
7 1 2 4 8
10 2 5 5 9
10 7 3 6 2
3 6 3 10 1
1 4 9 4 5
10 10 5 8 10
7 7 1 2 2
3 1 9 7 10
8 10 4 7 1
2 4 8 4 10
4 5 4 2 2
3 1 10 4 9
6 5 4 10 6
6 8 2 1 3
7 10 5 1 6
9 10 1 5 9
1 1 4 10 4
8 9 2 9 4
2 3 4 10 7
7 10 8 1 9
1 10 9 7 9
3 1 4 9 2
9 4 3 2 10
4 4 10 9 7
6 1 1 1 6
2 4 4 2 2
5 1 9 10 3
6 5 9 2 2
5 3 4 10 9
9 9 5 6 4
10 10 6 10 8
1 8 1 10 1
5 8 4 3 2
2 1 1 2 5
6 3 10 5 3
5 10 10 7 6
3 2 7 6 7
8 1 2 2 7
2 1 10 1 10
1 6 7 3 7
7 6 5 3 3
10 9 5 3 2
3 4 5 7 4
9 9 3 5 9
9 7 8 8 9
10 3 1 9 1
9 4 3 5 8
	<< output
88
����ð�: 0.xxx��
*/