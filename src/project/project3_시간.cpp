//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

namespace jnu_project3_time {

	//�־��� �۾��� ����ð��� �����Ѵ�.
	void measureProcessTime(function<void(void)> process) {
		clock_t duration = -clock(); //�۾��ð� ���� ����
		process(); //�۾��� �����Ѵ�.
		duration += clock(); //�۾��ð� ���� ����
		cout.precision(3);
		cout << fixed << "����ð�: " << ((double)duration / CLOCKS_PER_SEC) << "��" << endl;
	}

	int main() {
		int N; cin >> N; //N ���� �Է¹���

		//�������� �־����� Ai, Bi�� ���� Ai - Bi = Si��� ġȯ����. �׷���
		//�־��� ������ ������ ������ ���� S = {S1, S2, ..., Sn}�� �� ���ҿ� ����
		//|S1+T| + |S2+T| + ...+ |Sn+T| �� �ּҰ� �Ǵ� T�� ������ ���ϴ� ������ �����ϴ�.
		//���� �ϴ� ������ �ϱ� ���� Ai, Bi�� ���� �������� ���� Si= Ai-Bi = Si�� ��������.
		vector<int> S(N); // �� ��� i�� ���� Ai - Bi ���� �����ϴ� �迭

		for (int i = 0; i < N; i++) {
			int A, B; cin >> A >> B; //i ��° ��ӿ� ���� A, B�� �Է� �ް�
			S[i] = A - B; // ���̸� �����Ѵ�.
		}

		//�־��� �۾��� ����ð��� �����Ѵ�.
		measureProcessTime([&N, &S]() {

			//|S1+T| + |S2+T| + ...+ |Sn+T| �� �ּҰ� �Ǵ� T�� ���ϴ� ������ ����� '��������'�� ������ �ִ�.
			//���� ������ (|S1-T| + |S2-T| + ...+ |Sn-T|)/n�� ���ϸ�, ���� ������ �ּҰ� �Ǵ�
			//T�� ���� S1, S2, ..., Sn�� �߾Ӱ����� �˷��� ������, �� �� n�� ¦������ Ȧ�������� ���� �� ������ ���̰� �ִ�.
			//	i) n�� Ȧ���� ���
			//		�߾Ӱ��� 1���̹Ƿ� �ּҰ� �Ǵ� T�� ������ 1���̴�.
			//	ii) n�� ¦���� ���
			//		S�� �������� �������� �� n/2��° ���� n/2 + 1��° ������ ��� ���� T�� �� �� �ִ�.

			//���� ������ Ǯ�� ���ؼ��� �߾Ӱ��� ���ؾ� �ϸ�, �̸� ���ؼ� S�� �������� ������ �ʿ��ϴ�.
			sort(S.begin(), S.end());

			//�������� ���� ¦��, Ȧ�������� ���� ���� �ٸ� ���� ����Ѵ�.
			if (N % 2 != 0)
				cout << 1 << endl; //Ȧ���� ��� ������ T�� ������ 1�̴�.
			else
				cout << S[N / 2] - S[N / 2 - 1] + 1 << endl; //¦���� ��� ������ T�� ������ ��� �� �� ������ ��� �ڿ����̴�.

		});

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
//int main() { return jnu_project3_time::main(); }

/*
	>> input
1
5 4
	<< output
1

	>> input
2
10 11
20 17
	<< output
5

	>> input
2
30 25
20 18
	<< output
4

	>> input
3
10 13
20 15
30 34
	<< output
1
*/