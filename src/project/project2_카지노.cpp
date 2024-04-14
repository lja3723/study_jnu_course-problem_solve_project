//소프트웨어공학과 201986 이장안

#include <iostream>
#include <vector>
#include <functional>
#include <time.h>

using namespace std;

namespace jnu_project2_casino {

	//5개의 카드 리스트를 표현하는 클래스
	class CardList {
	private:
		vector<int> list; //5개의 카드 리스트

		//주어진 5개의 카드 리스트(list)에서의 costMax를 계산한다.
		int calculateCostMax() const {
			int costMax = 0;

			//5개 중에서 3개를 뽑는 모든 경우의 수를 탐색하면서,
			for (int i = 0; i < 3; i++)
				for (int j = i + 1; j < 4; j++)
					for (int k = j + 1; k < 5; k++)
						// 그 중에서 합의 1의 자리 수가 최대가 되는 경우를 계산한다.
						costMax = max(costMax, (list[i] + list[j] + list[k]) % 10);

			return costMax;
		}

	public:
		CardList() : list(5, 0) {} //생성 시 길이가 5이고 원소가 0인 vector로 초기화한다.
		int& operator[](int index) { return list[index]; } //operator[]의 오버로딩으로 첨자 연산을 허용한다.
		const int getCostMax() const { return calculateCostMax(); }; //5개 리스트에서의 costMax를 반환한다.
	};


	//주어진 작업의 수행시간을 측정하는 클래스이다.
	class ProcessingTimeMeter {
	private:
		function<void(void)> process; //시간을 측정할 작업
	public:
		ProcessingTimeMeter(function<void(void)> process) : process(process) {}

		double measureTime() {
			clock_t duration = -clock(); //작업시간 측정 시작
			process(); //작업을 실행한다.
			duration += clock(); //작업시간 측정 종료

			return (double)duration / CLOCKS_PER_SEC; //측정된 작업시간(ms)를 리턴한다.
		}
	};


	//stdin에서으로 들어오는 데이터를 입력받는다.
	void inputDataFromStdin(int& N, vector<CardList>& cardLists) {
		cin >> N; //참가 인원을 입력받음

		//각 참가인원에게 주어진 5개의 카드 리스트를 입력받음
		for (int n = 1; n <= N; n++) {
			//n번 참가자에게 주어진 카드 리스트를 입력 받는다.
			for (int i = 0; i < 5; i++)
				cin >> cardLists[n][i];
		}
	}


	//참가자별 costMax가 담긴 배열을 초기화한다.
	void initCostMaxVector(const int& N, const vector<CardList>& cardLists, vector<int>& costMax) {
		for (int n = 1; n <= N; n++)
			costMax[n] = cardLists[n].getCostMax(); //n번 참가자의 카드리스트에서 costMax를 받아온 뒤, 그 값으로 costMax를 지정한다.
	}


	//costMax 배열을 이용하여 합의 일의 자리가 가장 큰 참가자의 번호를 반환한다.
	//단 그러한 참가자가 여러 명인 경우, 참가자 번호가 큰 것을 선택한다.
	int getMaximumParticipant(const int& N, const vector<int>& costMax) {
		int maximum = N;

		//배열의 뒤에서부터 탐색한다.
		for (int n = N - 1; n >= 0; n--) {

			//가장 큰 값을 발견한 경우, 그 값으로 갱신한다.
			if (costMax[n] > costMax[maximum])
				maximum = n;
		}

		return maximum; //합의 일의 자리가 가장 큰 참가자의 번호를 반환
	}


	int main() {
		//문제에서 주어질 수 있는 참가 인원의 최댓값이다.
		const int PopulationMax = 1'000;
		
		int N; //참가 인원이다.

		//이 배열의 각각의 원소에는 다음의 값이 저장된다:
		//	"주어진 5장의 카드 중 3장을 고르는 모든 경우의 수를 확인했을 때,
		//	그 경우의 수 중 카드 3장의 합의 1의 자리 수가 가장 크게 되는 최댓값"
		// 
		//이 값의 이름을 "costMax"라고 이름 붙이자. 이 때, costMax[n]이 의미하는 것은 다음과 같다:
		//	n번 참가자에게 주어진 5개 카드로 만들 수 있는 costMax
		//	즉, n번째 참가자가 만들 수 있는 가장 큰 값이다.
		vector<int> costMax(PopulationMax + 1);

		//이 배열의 원소는 "원소 형식이 int이고 길이가 5인 배열"이고,
		//cardLists[n]이 의미하는 것은 다음과 같다:
		//	n번 참가자에게 주어진 5개의 카드의 목록
		vector<CardList> cardLists(PopulationMax + 1);

		//stdin에서으로 들어오는 데이터를 입력받는다.
		//이 작업은 시간 측정을 하지 않는다.
		inputDataFromStdin(N, cardLists);

		//시간을 측정할 작업을 정의한다.
		ProcessingTimeMeter meter([&N, &cardLists, &costMax] {
			//참가자별 costMax가 담긴 배열을 초기화한다.
			initCostMaxVector(N, cardLists, costMax);	

			//costMax 배열을 이용하여 합의 일의 자리가 가장 큰 참가자의 번호를 계산한 뒤, 그 값을 출력한다.
			cout << getMaximumParticipant(N, costMax) << endl;
		});

		//작업의 수행 시간을 측정한 뒤, 수행 시간을 출력한다.
		printf("%실행시간: %.3lf초\n", meter.measureTime());
		
		return 0;
	}
}

//문제풀이를 담당하는 main문을 호출한다.
//int main() { return jnu_project2_casino::main(); }


/*
	>> input
3
9 5 4 5 7
1 1 1 1 1
10 3 2 3 2
	<< output
1
실행시간: xxx초

	>> input
2
1 1 1 1 1
1 1 1 1 1
	<< output
2
실행시간: xxx초

	>> input
3
9 5 4 5 7
1 1 1 1 1
10 3 2 3 2
	<< output
1
실행시간: xxx초

	>> input
100
8 1 7 3 8
7 3 10 7 9
2 5 3 7 7
10 2 8 4 5
10 4 8 9 5
2 1 6 9 1
6 10 10 2 7
1 10 7 9 5
7 4 8 10 4
7 10 4 9 6
5 2 6 2 10
3 1 5 6 9
1 1 9 7 7
9 2 9 4 2
7 6 1 2 2
9 2 10 3 10
4 5 1 3 3
10 1 4 2 10
9 7 5 2 1
7 9 7 8 8
2 6 8 10 7
7 6 9 4 3
1 1 9 4 7
1 2 1 1 7
3 10 1 1 7
3 8 9 5 7
6 5 6 10 8
9 10 10 10 9
5 10 9 8 3
8 8 2 5 3
4 10 4 6 4
9 6 9 10 4
2 5 1 10 10
3 10 10 3 5
3 6 1 3 2
9 7 7 8 1
8 5 5 2 8
2 5 1 3 2
2 9 10 8 5
5 8 10 6 6
6 6 4 4 2
7 5 6 4 5
4 3 7 4 2
8 5 10 5 8
4 4 3 8 1
8 4 7 4 10
1 10 5 1 3
4 2 2 8 8
7 10 4 2 1
9 7 10 1 2
1 10 1 6 4
8 2 2 9 3
2 1 5 7 3
7 1 2 4 8
10 2 5 5 9
10 7 3 6 2
3 6 3 10 1
1 4 9 4 5
10 10 5 8 10
7 7 1 2 2
3 1 9 7 10
8 10 4 7 1
2 4 8 4 10
4 5 4 2 2
3 1 10 4 9
6 5 4 10 6
6 8 2 1 3
7 10 5 1 6
9 10 1 5 9
1 1 4 10 4
8 9 2 9 4
2 3 4 10 7
7 10 8 1 9
1 10 9 7 9
3 1 4 9 2
9 4 3 2 10
4 4 10 9 7
6 1 1 1 6
2 4 4 2 2
5 1 9 10 3
6 5 9 2 2
5 3 4 10 9
9 9 5 6 4
10 10 6 10 8
1 8 1 10 1
5 8 4 3 2
2 1 1 2 5
6 3 10 5 3
5 10 10 7 6
3 2 7 6 7
8 1 2 2 7
2 1 10 1 10
1 6 7 3 7
7 6 5 3 3
10 9 5 3 2
3 4 5 7 4
9 9 3 5 9
9 7 8 8 9
10 3 1 9 1
9 4 3 5 8
	<< output
88
실행시간: 0.xxx초
*/