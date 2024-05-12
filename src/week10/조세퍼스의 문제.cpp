//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

namespace week10_josephus_problem {

	//큐에 1부터 N의 자연수를 순서대로 추가한다.
	void init_queue(queue<int>& q, int N) {
		for (int i = 1; i <= N; i++)
			q.push(i); //i번째 자연수를 큐에 추가한다.
	}

	//큐의 맨 앞 원소를 맨 뒤에 넣는 과정을 M회 반복한다.
	void roll_queue(queue<int>& q, int M) {
		for (int i = 0; i < M; i++) {
			q.push(q.front()); //맨 앞 원소를 뒤에 넣은 후
			q.pop(); //맨 앞 원소를 제거한다.
		}
	}

	void test() {
		int N, M; cin >> N >> M; //N, M 입력

		queue<int> q; //큐 선언
		init_queue(q, N); //큐 초기화

		while (!q.empty()) { //모든 사람이 지목받을 때까지 반복한다.
			roll_queue(q, M - 1); //큐를 M - 1번 회전한다.
			cout << q.front() << " "; //맨 앞 사람을 지목한뒤
			q.pop(); //그 사람으 제외한다.
		}

		cout << endl;
	}

	int main() {
		int T; cin >> T; //테스트케이스 수
		while (T--) test(); //T회 만큼 반복
		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
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