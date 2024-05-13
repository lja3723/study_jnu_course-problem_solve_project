//소프트웨어공학과 201986 이장안
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

namespace jnu_project4_event {

	//주어진 작업의 수행시간을 측정한다.
	void measureProcessTime(function<void(void)> process) {
		clock_t duration = -clock(); //작업시간 측정 시작
		process(); //작업을 실행한다.
		duration += clock(); //작업시간 측정 종료
		cout.precision(3);
		cout << fixed << "실행시간: " << ((double)duration / CLOCKS_PER_SEC) << "초" << endl;
	}

	//정렬된 v에 대해 중앙값을 구한다.
	int getMidValue(const vector<int>& sorted_v) {
		int sz = sorted_v.size(); //배열의 크기

		//홀수 배열인 경우
		if (sz % 2 != 0) {
			return sorted_v[sz / 2]; //중앙에 위치한 값 반환
		}
		//짝수 배열인 경우
		else {
			//중앙에 위치한 두 값의 평균을 소수점을 버림한 값을 반환한다.
			return (sorted_v[sz / 2 - 1] + sorted_v[sz / 2]) / 2;
		}
	}

	//주어진 문제를 정해진 알고리즘을 이용하여 풀이한다.
	void process(int N, vector<int>& xpos, vector<int>& ypos) {

		//참가자의 거리는 맨해튼 거리(Manhattan Distance)이므로,
		//x좌표에서의 거리의 최소값과 y좌표의 거리의 최소값을 구하는 것은 서로 별개이다.
		//정수가 담긴 배열 N = {N1, N2, ... , Nn}이 있을 경우, sum(i=1~n, |Ni - K|)이 최소가 되는 K는
		//절대평균의 원리에 의하여 N 원소들의 중앙값이 된다. (n이 홀수인 경우)
		//n이 짝수인 경우, n/2 번째와 수와 그 다음수의 사이의 모든 값이 K가 될 수 있다.
		//본 알고리즘에서는 n/2 번째 수와 그 다음수의 평균을 소수점을 절삭한 값으로 계산한다.

		//중앙값을 구하기위해, xpos와 ypos를 각각 오름차순 정렬한다(독립이므로).
		sort(xpos.begin(), xpos.end());
		sort(ypos.begin(), ypos.end());

		//xpos와 ypos의 중앙값을 계산한다.
		int ans_x = getMidValue(xpos);
		int ans_y = getMidValue(ypos);

		//결과를 출력한다.
		cout << ans_x << " " << ans_y << endl;
	}

	int main() {
		int N; cin >> N; //참가인원수 입력
		vector<int> xpos(N); //i번째 참가인원의 x좌표는 xpos[i]
		vector<int> ypos(N); //i번째 참가인원의 y좌표는 ypos[i]

		for (int i = 0; i < N; i++) {
			cin >> xpos[i] >> ypos[i]; //i번째 참가인원의 x, y좌표를 입력받는다.
		}

		//인자로 들어온 모든 코드의 실행시간을 측정한뒤, 출력한다.
		measureProcessTime([&N, &xpos, &ypos]() { process(N, xpos, ypos); });

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
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