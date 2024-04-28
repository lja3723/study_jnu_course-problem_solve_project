//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

namespace jnu_project3_rectangle {

	//주어진 작업의 수행시간을 측정한다.
	void measureProcessTime(function<void(void)> process) {
		clock_t duration = -clock(); //작업시간 측정 시작
		process(); //작업을 실행한다.
		duration += clock(); //작업시간 측정 종료
		cout.precision(3);
		cout << fixed << "실행시간: " << ((double)duration / CLOCKS_PER_SEC) << "초" << endl;
	}

	int main() {
		int N; cin >> N; //N 입력받기
		
		vector<int[2]> side(N); //직사각형의 가로 세로를 저장하는 변수

		for (int i = 0; i < N; i++) {
			cin >> side[i][0]; //직사각형의 한 변의 길이
			cin >> side[i][1]; //다른 변의 길이
		}

		//주어진 작업의 수행시간을 측정한다.
		measureProcessTime([&N, &side]() {

			//N번째 직사각형을 N번째 위치에 배치하는데, 직사각형을 가로로 놓을 지 세로로 놓을지에 따라
			//문제에서의 '윗둘레 길이'가 달라진다.
			//만약 모든 직사각형에 대해 가로 또는 세로로 배열하는 모든 경우의 수를 탐색한다면,
			//O(2^1000)이라는 천문학적인 시간이 소요되므로 전체 탐색은 적합하지 않다.

			//하지만 만약 현재 i - 1번째까지 사각형을 배열했고, 그 때의 윗둘레 길이는 최댓값이라고 가정하면 어떨까?
			//그러면 i번째 직사각형을 배열할 때 두 가지 경우만 확인해 보면 된다.
			//i - 1 번째까지 직사각형을 배열한 상황을 가정해보자. 이 상황은 두 가지로 나뉜다.
			//	i) i - 1 번째 직사각형은 회전하지 않은 채 배열되었다.
			//	ii) i - 1 번째 직사각형은 회전한 채 배열되었다.
			// 두 가지 상황 각각에 대해 윗둘레 길이가 최대값이라고 가정하자. 그러면 각 상황에 대한
			// 윗 둘레 길이가 최댓값인 상황을 저장하는 배열이 경우마다 1개씩 필요한데, 이를 non_rotated, rotated라고 하자.

			vector<int> non_rotated(N); //i번째 사각형을 주어진 그대로 배치했을 때의 윗둘레 길이의 최댓값
			vector<int> rotated(N); //i번째 사각형을 주어진 상태에서 90도 회전해 배치했을 때의 윗둘의 길이의 최댓값

			//첫 번째 사각형은 이전 상황을 고려하지 않아도 되므로, 각 경우에 대해 직사각형의 변을 저장하자.
			non_rotated[0] = side[0][0]; //0번째 직사각형을 그대로 배열했을 때 윗둘래 최대값
			rotated[0] = side[0][1]; //0번째 직사각형을 회전해 배열했을 때 윗 둘레 최대값

			//이제 나머지 직사각형에 대해서도 non_rotated와 rotated를 계산해 보자.
			for (int i = 1; i < N; i++) {

				//i번째 직사각형에 대해서 그대로 배치하게 된다면, 그대로 배치할 때의 윗둘레 최대값은 다음과 같다.
				//	i) i - 1번째 직사각형이 그대로 배치되었을 상황에서 i번째 직사각형을 그대로 배치하는 경우
				//	ii) i - 1번째 직사각형이 회전되어 배치되었을 상황에서 i번째 직사각형을 그대로 배치하는 경우
				//각 경우에 대해 i번째 직사각형의 윗 부분의 길이 + abs(i - 1번째 직사각형의 옆부분의 길이와 i번째 직사각형의 옆부분의 길이의 차이)을 계산해
				//더 큰 값을 선택한다.

				non_rotated[i] = side[i][0]/*i번째 직사각형의 윗부분 길이*/ + max( // i), ii) 번째 경우 중 최대값을 선택한다.
					abs(side[i - 1][1] - side[i][1]) + non_rotated[i - 1], // i) 번째 경우
					abs(side[i - 1][0] - side[i][1]) + rotated[i - 1]);	   // ii) 번째 경우

				//i번째 직사각형에 대해 회전하여 배치하게 된다면, 그 때의 윗둘의 최대값도 위처럼 구할 수 있다.
				rotated[i] = side[i][1] + max( // i), ii) 번째 경우 중 최대값을 선택한다.
					abs(side[i - 1][1] - side[i][0]) + non_rotated[i - 1], // i) 번째 경우
					abs(side[i - 1][0] - side[i][0]) + rotated[i - 1]);	   // ii) 번째 경우
			}

			//i 번째 직사각형까지 모두 배치하였다. 이제 두 경우에서 최대값을 구하면 그것이 곧 문제에서 구하고자하는 답이다.
			cout << max(non_rotated[N - 1], rotated[N - 1]) << endl;

		});

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
//int main() { return jnu_project3_rectangle::main(); }

/*
	>> input
5
2 5
3 8
1 10
7 14
2 5
	<< output
68
*/