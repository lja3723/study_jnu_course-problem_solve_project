//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

namespace jnu_project3_time {

	//주어진 작업의 수행시간을 측정한다.
	void measureProcessTime(function<void(void)> process) {
		clock_t duration = -clock(); //작업시간 측정 시작
		process(); //작업을 실행한다.
		duration += clock(); //작업시간 측정 종료
		cout.precision(3);
		cout << fixed << "실행시간: " << ((double)duration / CLOCKS_PER_SEC) << "초" << endl;
	}

	int main() {
		int N; cin >> N; //N 값을 입력받음

		//문제에서 주어지는 Ai, Bi에 대해 Ai - Bi = Si라고 치환하자. 그러면
		//주어진 문제는 임의의 정수의 집합 S = {S1, S2, ..., Sn}의 각 원소에 대해
		//|S1+T| + |S2+T| + ...+ |Sn+T| 가 최소가 되는 T의 개수를 구하는 문제와 동일하다.
		//따라서 일단 간단히 하기 위해 Ai, Bi를 따로 저장하지 말고 Si= Ai-Bi = Si를 저장하자.
		vector<int> S(N); // 각 약속 i에 대해 Ai - Bi 값을 저장하는 배열

		for (int i = 0; i < N; i++) {
			int A, B; cin >> A >> B; //i 번째 약속에 대한 A, B를 입력 받고
			S[i] = A - B; // 차이를 저장한다.
		}

		//주어진 작업의 실행시간을 측정한다.
		measureProcessTime([&N, &S]() {

			//|S1+T| + |S2+T| + ...+ |Sn+T| 가 최소가 되는 T를 구하는 문제는 통계의 '절대편차'와 관련이 있다.
			//절대 편차는 (|S1-T| + |S2-T| + ...+ |Sn-T|)/n을 말하며, 절대 편차가 최소가 되는
			//T의 값은 S1, S2, ..., Sn의 중앙값으로 알려져 있으며, 이 때 n이 짝수인지 홀수인지에 따라 그 개수가 차이가 있다.
			//	i) n이 홀수인 경우
			//		중앙값은 1개이므로 최소가 되는 T의 개수는 1개이다.
			//	ii) n이 짝수인 경우
			//		S를 오름차순 정렬했을 때 n/2번째 수와 n/2 + 1번째 사이의 모든 수가 T가 될 수 있다.

			//따라서 문제를 풀기 위해서는 중앙값을 구해야 하며, 이를 위해선 S의 오름차순 정렬이 필요하다.
			sort(S.begin(), S.end());

			//데이터의 수가 짝수, 홀수인지에 따라 서로 다른 답을 출력한다.
			if (N % 2 != 0)
				cout << 1 << endl; //홀수인 경우 가능한 T의 개수는 1이다.
			else
				cout << S[N / 2] - S[N / 2 - 1] + 1 << endl; //짝수인 경우 가능한 T의 개수는 가운데 두 수 사이의 모든 자연수이다.

		});

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
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