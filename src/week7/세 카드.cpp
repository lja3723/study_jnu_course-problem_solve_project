//����Ʈ������а� 201986 �����
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace week7_three_cards {

	//cards���� �� ���� �̾� �� ���� m�� ������� �� �ִ��� ���θ� Ȯ���Ѵ�.

	//���� ��� ����� ���� Ž���ϱ� ���� ī�� ����Ʈ���� �����ϰ� 3���� ��� �̾Ҵٸ�
	//�ð����⵵�� O(N * N * N), �� �־��� ��� 1000^3(10��)���� ������ �����ϰ� �ǹǷ� �ð��ʰ��� �߻����� ���̴�.

	//�׷��� ī�� �� ���� �켱 ���� �� ������ �� ���� ī�帮��Ʈ���� '����' �̴� ���� �ƴ϶�,
	//�� ������ ������� ���� �� �� ����� �´��� �����˻����� Ž�������μ�
	//�ð����⵵�� O(N * N * log N) ���� ȹ�������� ���̴� ���� �����ϴ�!

	bool is_m_possible(const vector<int>& cards, int m) {
		int N = cards.size(); //ī�帮��Ʈ ũ�⸦ �̸� ����

		//�ϴ� ī�帮��Ʈ���� ī�� �� ���� ���� ��� ���� �̴´�.
		for (int i = 0; i < N; i++) {
			for (int j = i; j < N; j++) {

				//�׸��� ������ �� ���� ī�� third�� ���� m�� �̿��Ͽ� ����Ѵ�.
				int third = m - cards[i] - cards[j];

				//third�� ��¥ ī�帮��Ʈ�� �����ϴ��� Ȯ���� ��, �ִٸ� m�� ������ ��÷��ȣ��� �ǹ��̴�.
				if (binary_search(cards.begin(), cards.end(), third))
					return true;
			}
			//������ ������ �߰��� ������ ��� ����� ���� Ž���Ѵ�.
		}		

		//��� ��츦 Ž���ߴµ��� m�� ���� �� �ִ� ������ �߰ߵ��� ���� ����.
		return false;
	}

	int main() {
		int N, M; cin >> N >> M; // N, M�� �Է� ����

		vector<int> cards(N), mlist(M);
		for (int i = 0; i < N; i++) cin >> cards[i]; //���� �� �ִ� ī�� ������ �����Ѵ�.
		for (int i = 0; i < M; i++) cin >> mlist[i]; //������ ��÷��ȣ�� �����Ѵ�.

		sort(cards.begin(), cards.end()); //cards�� ������������ �����Ѵ�.
		sort(mlist.begin(), mlist.end()); //mlist�� ������������ �����Ѵ�.

		vector<int> answer; //������� �� �ִ� M�� ��� �迭

		//��� M�� ���Ͽ� ������ m���� answer�� �����Ѵ�.
		for (int m = 0; m < M; m++) {
			//m�� �� ���� ī���� ������ ����� �� �� ������ answer�� �߰��Ѵ�.
			if (is_m_possible(cards, mlist[m]))
				answer.push_back(mlist[m]);
		}

		//������ m�� �ϳ��� ���� ���; NO�� ����ϰ� ���α׷��� �����Ѵ�.
		if (answer.empty()) {
			cout << "NO";
			return 0;
		}

		//������ ��� m�� ����Ʈ�� �������� �����Ͽ� �� �ٿ� ����Ѵ�.
		//�ռ� mlist�� �������� ���ĵ� �迭�̹Ƿ�, answer�� ������������ ���ĵǾ� ������ ������ �� �ִ�.
		for_each(answer.begin(), answer.end(), [](int e) { cout << e << " "; });

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
//int main() { return week7_three_cards::main(); }

/*
	>> input
3 5
1 2 3
1 2 3 4 5
	<< output
3 4 5

	>> input
10 5
1 2 3 4 5 6 7 8 9 10
1 2 20 30 40
	<< output
20 30
*/