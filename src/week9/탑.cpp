//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

namespace week9_tower {

	//Ÿ���� ǥ���ϴ� ����ü
	struct Tower {
		int idx; //ž�� ��ġ(�ε���)
		int height; //ž�� ����
		int targetIdx; //�� ��ȣ�� �����ϴ� ž�� ��ġ
	};

	int main() {
		int N; cin >> N; //ž�� �� �Է�

		vector<Tower> tower(N + 1); //i��° �ε������� i��° ž�� ���̰� ����ȴ�.
										//0��° �ε����� ���̷� �Ѵ�.

		//i��° ž�� ���� ������ �Է¹޴´�. �׸��� �� Ÿ���� ��ġ�� �ʱ�ȭ�Ѵ�.
		for (int i = 1; i <= N; i++) {
			cin >> tower[i].height; //���� ���
			tower[i].idx = i; //��ġ �ʱ�ȭ
		}

		stack<Tower> ableList; //���� ��ȣ ���� ���ɼ��� ���� ž���� ��������

		for (int i = 1; i <= N; i++) {
			tower[i].targetIdx = 0; //i��° ž ��ȣ�� ������ �ĺ� (�ʱⰪ�� 0���� ��)

			//������ ����Ʈ�� ������� �ʰ�, ������ ����Ʈ �� ���� �ֱ��� ž�� ���̰� ���� �ٷ�� ž ���̺��� ���� ���
			//�׷� ž���� ������ ��ȣ�� ���Ź��� ���ɼ��� �����Ƿ� ���� ����Ʈ���� �����Ѵ�.
			while (!ableList.empty() && ableList.top().height < tower[i].height)
				ableList.pop();
			
			//���� ����Ʈ�� ������� ������, ����Ʈ �� ���� �ֱ��� ž�� �� ���� ž�� Ÿ���� �ȴ�.
			if (!ableList.empty())
				tower[i].targetIdx = ableList.top().idx;

			//���� ž�� ���� ����Ʈ�� �ִ´�.
			ableList.push(tower[i]);
		}

		//�� ž�� ���� �� ��ȣ�� �����ϴ� ž�� ��ġ�� ����Ѵ�.
		for (int i = 1; i <= N; i++) {
			cout << tower[i].targetIdx << " ";
		}

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
//int main() { return week9_tower::main(); }

/*
	>> input
5
6 9 5 7 4
	<< output
0 0 2 2 4
*/

//    @
//    @
//    @     @
// @  @     @
// @  @  @  @  
// @  @  @  @  @
// @  @  @  @  @
// @  @  @  @  @
// @  @  @  @  @
//---------------
// 6  9  5  7  4