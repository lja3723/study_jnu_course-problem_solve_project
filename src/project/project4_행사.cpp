//����Ʈ������а� 201986 �����
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

namespace jnu_project4_event {

	//�־��� �۾��� ����ð��� �����Ѵ�.
	void measureProcessTime(function<void(void)> process) {
		clock_t duration = -clock(); //�۾��ð� ���� ����
		process(); //�۾��� �����Ѵ�.
		duration += clock(); //�۾��ð� ���� ����
		cout.precision(3);
		cout << fixed << "����ð�: " << ((double)duration / CLOCKS_PER_SEC) << "��" << endl;
	}

	//���ĵ� v�� ���� �߾Ӱ��� ���Ѵ�.
	int getMidValue(const vector<int>& sorted_v) {
		int sz = sorted_v.size(); //�迭�� ũ��

		//Ȧ�� �迭�� ���
		if (sz % 2 != 0) {
			return sorted_v[sz / 2]; //�߾ӿ� ��ġ�� �� ��ȯ
		}
		//¦�� �迭�� ���
		else {
			//�߾ӿ� ��ġ�� �� ���� ����� �Ҽ����� ������ ���� ��ȯ�Ѵ�.
			return (sorted_v[sz / 2 - 1] + sorted_v[sz / 2]) / 2;
		}
	}

	//�־��� ������ ������ �˰����� �̿��Ͽ� Ǯ���Ѵ�.
	void process(int N, vector<int>& xpos, vector<int>& ypos) {

		//�������� �Ÿ��� ����ư �Ÿ�(Manhattan Distance)�̹Ƿ�,
		//x��ǥ������ �Ÿ��� �ּҰ��� y��ǥ�� �Ÿ��� �ּҰ��� ���ϴ� ���� ���� �����̴�.
		//������ ��� �迭 N = {N1, N2, ... , Nn}�� ���� ���, sum(i=1~n, |Ni - K|)�� �ּҰ� �Ǵ� K��
		//��������� ������ ���Ͽ� N ���ҵ��� �߾Ӱ��� �ȴ�. (n�� Ȧ���� ���)
		//n�� ¦���� ���, n/2 ��°�� ���� �� �������� ������ ��� ���� K�� �� �� �ִ�.
		//�� �˰��򿡼��� n/2 ��° ���� �� �������� ����� �Ҽ����� ������ ������ ����Ѵ�.

		//�߾Ӱ��� ���ϱ�����, xpos�� ypos�� ���� �������� �����Ѵ�(�����̹Ƿ�).
		sort(xpos.begin(), xpos.end());
		sort(ypos.begin(), ypos.end());

		//xpos�� ypos�� �߾Ӱ��� ����Ѵ�.
		int ans_x = getMidValue(xpos);
		int ans_y = getMidValue(ypos);

		//����� ����Ѵ�.
		cout << ans_x << " " << ans_y << endl;
	}

	int main() {
		int N; cin >> N; //�����ο��� �Է�
		vector<int> xpos(N); //i��° �����ο��� x��ǥ�� xpos[i]
		vector<int> ypos(N); //i��° �����ο��� y��ǥ�� ypos[i]

		for (int i = 0; i < N; i++) {
			cin >> xpos[i] >> ypos[i]; //i��° �����ο��� x, y��ǥ�� �Է¹޴´�.
		}

		//���ڷ� ���� ��� �ڵ��� ����ð��� �����ѵ�, ����Ѵ�.
		measureProcessTime([&N, &xpos, &ypos]() { process(N, xpos, ypos); });

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
//int main() { return jnu_project4_event::main(); }

/*
	>> input
2
1 1
4 1
	<< output
2 1
	<< output(also answer)
1 1
	<< output(also answer)
3 1
	<< output(also answer)
4 1

	>> input
6
1 0
3 0
5 0
7 0
9 0
11 0
	<< output
5 0
	<< output(also answer)
6 0
	<< output(also answer)
7 0

	>> input
9
1 16
3 12
5 6
7 10
9 8
11 4
13 14
15 2
17 18
	<< output
9 10
*/