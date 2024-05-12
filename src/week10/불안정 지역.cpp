//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

namespace week10_unstable_area {

	//���ø� ǥ���ϴ� Ŭ����
	class City {
	public:
		int val; //������ �ҵ����
		int idx; //������ ����

		//���ø� ���Ѵ�. (less)
		bool operator<(const City& c) const {
			return val < c.val;
		}

		//���ø� ���Ѵ� (greater)
		bool operator>(const City& c) const {
			return val > c.val;
		}
	};

	//cost�� �ִ��� City�� top�� �ִ� �켱���� ť�� ����
	using MaxPq = priority_queue<City>;
	//cost�� �ּ��� City�� top�� �ִ� �켱���� ť�� ����
	using MinPq = priority_queue<City, vector<City>, greater<City>>;

	//�ִ� ������ �ҵ�� ���� ������ �ҵ��� ��(�Ҿ��� ����)�� ����Ѵ�.
	int getUnstableRatio(const MaxPq& max, const MinPq& min) {
		return max.top().val - min.top().val;
	}

	//a <= x <= b �� �����ϴ��� �˻��Ѵ�.
	bool isRanged(int a, int x, int b) {
		return a <= x && x <= b;
	}

	void test() {
		int N, K; cin >> N >> K; //N, K �Է�
		vector<City> cities; //n���� ���ø� ����

		MaxPq maxPq; //cost�� �ִ��� City�� top�� �ִ� �켱���� ť
		MinPq minPq; //cost�� �ּ��� City�� top�� �ִ� �켱���� ť

		//�� ������ �ҵ������ ��´�.
		for (int i = 0; i < N; i++) {
			int cost; cin >> cost; //i��° ���� �ҵ� �Է�
			cities.push_back({ cost, i }); //City�� �߰�
		}

		//�Ҿ��� ����(�ִ�, �����ҵ浵���� �ҵ���)�� ���ϱ� ����, ù K ������ ���ø� �켱����ť�� �߰��Ѵ�.
		for (int i = 0; i < K; i++) {
			maxPq.push(cities[i]);
			minPq.push(cities[i]);
		}

		int maxUnstableRatio = getUnstableRatio(maxPq, minPq);

		for (int i = K; i < N; i++) {
			int minRange = i - K + 1; //���� Ž���ϴ� ������ �ּ�
			int maxRange = i; //���� Ž���ϴ� ������ �ִ�

			//i��° ���ø� �ִ�ť, �ּ�ť�� ���� �߰��Ѵ�.
			maxPq.push(cities[i]);
			minPq.push(cities[i]);

			//maxPq�� top������ idx�� ���� Ž���ϰ� �ִ� ���� ���� �鵵�� �����Ѵ�.
			while (!maxPq.empty() && !isRanged(minRange, maxPq.top().idx, maxRange)) {
				maxPq.pop();
			}

			//minPq�� top������ idx�� ���� Ž���ϰ� �ִ� ���� ���� �鵵�� �����Ѵ�.
			while (!minPq.empty() && !isRanged(minRange, minPq.top().idx, maxRange)) {
				minPq.pop();
			}

			//���� Ž�� ������ �Ҿ��� ������ ����� ��, �ִ밪�̸� �ִ밪���� �����Ѵ�.
			maxUnstableRatio = max(maxUnstableRatio, getUnstableRatio(maxPq, minPq));
		}
		
		//�Ҿ��� ������ �ִ밡 �Ǵ� ���� ����Ѵ�.
		cout << maxUnstableRatio << endl;

	}

	int main() {
		int T; cin >> T; //�׽�Ʈ���̽� T
		while (T--) test(); //Tȸ��ŭ ���α׷� �ݺ�

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
//int main() { return week10_unstable_area::main(); }

/*
	>> input
1
7 3
10 2 5 3 7 9 1
	<< output
8
*/