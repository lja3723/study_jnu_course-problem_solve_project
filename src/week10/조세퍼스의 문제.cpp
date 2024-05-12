//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

namespace week10_josephus_problem {

	//ť�� 1���� N�� �ڿ����� ������� �߰��Ѵ�.
	void init_queue(queue<int>& q, int N) {
		for (int i = 1; i <= N; i++)
			q.push(i); //i��° �ڿ����� ť�� �߰��Ѵ�.
	}

	//ť�� �� �� ���Ҹ� �� �ڿ� �ִ� ������ Mȸ �ݺ��Ѵ�.
	void roll_queue(queue<int>& q, int M) {
		for (int i = 0; i < M; i++) {
			q.push(q.front()); //�� �� ���Ҹ� �ڿ� ���� ��
			q.pop(); //�� �� ���Ҹ� �����Ѵ�.
		}
	}

	void test() {
		int N, M; cin >> N >> M; //N, M �Է�

		queue<int> q; //ť ����
		init_queue(q, N); //ť �ʱ�ȭ

		while (!q.empty()) { //��� ����� ������� ������ �ݺ��Ѵ�.
			roll_queue(q, M - 1); //ť�� M - 1�� ȸ���Ѵ�.
			cout << q.front() << " "; //�� �� ����� �����ѵ�
			q.pop(); //�� ����� �����Ѵ�.
		}

		cout << endl;
	}

	int main() {
		int T; cin >> T; //�׽�Ʈ���̽� ��
		while (T--) test(); //Tȸ ��ŭ �ݺ�
		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
//int main() { return week10_josephus_problem::main(); }

/*
	>> input
2
4 2
7 3
	<< output
2 4 3 1
3 6 2 7 5 1 4
*/