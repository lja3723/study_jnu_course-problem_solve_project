//����Ʈ������а� 201986 �����
#include <iostream>
#include <functional>
#include <vector>

using namespace std;

namespace jnu_project4_delivery {

	//�־��� �۾��� ����ð��� �����Ѵ�.
	void measureProcessTime(function<void(void)> process) {
		clock_t duration = -clock(); //�۾��ð� ���� ����
		process(); //�۾��� �����Ѵ�.
		duration += clock(); //�۾��ð� ���� ����
		cout.precision(3);
		cout << fixed << "����ð�: " << ((double)duration / CLOCKS_PER_SEC) << "��" << endl;
	}

	//�־��� ������ ������ �˰����� �̿��Ͽ� Ǯ���Ѵ�.
	void process(int N, vector<int>& D) {
		//N�� ������ 1~10���� �ſ� �����Ƿ�, ������ ��� ����� ���� Ž���� �� �ִ�.
		//�� ���Ʈ������ �ǽ��Ѵ�.

		vector<int> answer; //������ ������ A
		bool hasAnswer = false; //������ A�� �ѹ� ���� �� �ִ� �� ����

		//������ A�� ù ��° ���� 1~N�� �� �����Ƿ�, ������ ��� ��츦 Ž���غ���.
		for (int n = 1; n <= N; n++) {
			vector<int> local(N); //�������� ���� �����ϴ� �ӽú���
			bool isPossible = true; //�������� ���� �������� ����
			local[0] = n; //ù ��° ���� n���� ����

			for (int i = 0; i < N - 1; i++) {
				local[i + 1] = local[i] + D[i]; //��Ÿ ���ڵ��� �̿��� Ai�� �����غ���.
				
				//������ Ai�� ������ 1~N�� ����ٸ� ������ ��찡 �ƴϴ�.
				if (!(1 <= local[i + 1] && local[i + 1] <= N)) {
					isPossible = false;
					break;
				}				
			}

			//���� �������� ���� �����ϰ� ó�� ���� ���
			if (isPossible && !hasAnswer) {
				answer = local; //������ ���� �������� �Ѵ�.
				hasAnswer = true; //���� ���ߴ�.
			}
			//������ ���� ���������� �̹� ���� �� �ִ� ���
			//A�� �������� �����Ƿ�, ������ ����Ѵ�.
			else if (isPossible && hasAnswer) {
				cout << "-1\n"; //�Ұ����� ���
				return;
			}
		}

		//������ A�� ���� ���. ������ ����Ѵ�.
		if (hasAnswer) {
			for (int i = 0; i < N; i++)
				cout << answer[i] << " "; //��� ���� ���
			cout << endl;
		}
		//������ A�� �ϳ��� ���� ���.
		else {
			cout << "-1\n"; //�Ұ����� ���
		}

	}

	int main() {
		int N; cin >> N; //������ ������ �Է¹޴´�.
		vector<int> D(N - 1);

		//��Ÿ ���ڵ� D�� �Է¹޴´�.
		for (int i = 0; i < N - 1; i++) {
			cin >> D[i];
		}

		//���ڷ� ���� ��� �ڵ��� ����ð��� �����ѵ�, ����Ѵ�.
		measureProcessTime([&N, &D]() { process(N, D); });

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
//int main() { return jnu_project4_delivery::main(); }

/*
	>> input
5
1 3 -2 1
	<< output
1 2 5 3 4

	>> input
5
2 2 -3 1
	<< output
1 3 5 2 3

	>> input
2
0
	<< output
-1
*/