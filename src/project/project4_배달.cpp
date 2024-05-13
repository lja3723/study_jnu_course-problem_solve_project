//소프트웨어공학과 201986 이장안
#include <iostream>
#include <functional>
#include <vector>

using namespace std;

namespace jnu_project4_delivery {

	//주어진 작업의 수행시간을 측정한다.
	void measureProcessTime(function<void(void)> process) {
		clock_t duration = -clock(); //작업시간 측정 시작
		process(); //작업을 실행한다.
		duration += clock(); //작업시간 측정 종료
		cout.precision(3);
		cout << fixed << "실행시간: " << ((double)duration / CLOCKS_PER_SEC) << "초" << endl;
	}

	//주어진 문제를 정해진 알고리즘을 이용하여 풀이한다.
	void process(int N, vector<int>& D) {
		//N의 범위가 1~10으로 매우 좁으므로, 가능한 모든 경우의 수를 탐색할 수 있다.
		//즉 브루트포스를 실시한다.

		vector<int> answer; //복구한 고유한 A
		bool hasAnswer = false; //고유한 A를 한번 구한 적 있는 지 여부

		//시퀀스 A의 첫 번째 수가 1~N일 수 있으므로, 가능한 모든 경우를 탐색해본다.
		for (int n = 1; n <= N; n++) {
			vector<int> local(N); //지역적인 답을 저장하는 임시변수
			bool isPossible = true; //지역적인 답이 가능한지 여부
			local[0] = n; //첫 번째 수를 n으로 가정

			for (int i = 0; i < N - 1; i++) {
				local[i + 1] = local[i] + D[i]; //델타 인코딩을 이용해 Ai를 복구해본다.
				
				//복구된 Ai의 범위가 1~N을 벗어난다면 가능한 경우가 아니다.
				if (!(1 <= local[i + 1] && local[i + 1] <= N)) {
					isPossible = false;
					break;
				}				
			}

			//계산된 지역적인 답이 가능하고 처음 계산된 경우
			if (isPossible && !hasAnswer) {
				answer = local; //지역적 답을 정답으로 한다.
				hasAnswer = true; //답을 구했다.
			}
			//지역적 답이 가능하지만 이미 계산된 적 있는 경우
			//A는 고유하지 않으므로, 정답을 출력한다.
			else if (isPossible && hasAnswer) {
				cout << "-1\n"; //불가능한 경우
				return;
			}
		}

		//고유한 A를 구한 경우. 정답을 출력한다.
		if (hasAnswer) {
			for (int i = 0; i < N; i++)
				cout << answer[i] << " "; //모든 원소 출력
			cout << endl;
		}
		//가능한 A가 하나도 없는 경우.
		else {
			cout << "-1\n"; //불가능한 경우
		}

	}

	int main() {
		int N; cin >> N; //소포의 개수를 입력받는다.
		vector<int> D(N - 1);

		//델타 인코딩 D를 입력받는다.
		for (int i = 0; i < N - 1; i++) {
			cin >> D[i];
		}

		//인자로 들어온 모든 코드의 실행시간을 측정한뒤, 출력한다.
		measureProcessTime([&N, &D]() { process(N, D); });

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
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