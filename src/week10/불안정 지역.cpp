//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

namespace week10_unstable_area {

	//도시를 표현하는 클래스
	class City {
	public:
		int val; //도시의 소득수준
		int idx; //도시의 순번

		//도시를 비교한다. (less)
		bool operator<(const City& c) const {
			return val < c.val;
		}

		//도시를 비교한다 (greater)
		bool operator>(const City& c) const {
			return val > c.val;
		}
	};

	//cost가 최대인 City가 top에 있는 우선순위 큐의 형식
	using MaxPq = priority_queue<City>;
	//cost가 최소인 City가 top에 있는 우선순위 큐의 형식
	using MinPq = priority_queue<City, vector<City>, greater<City>>;

	//최대 도시의 소득과 최저 도시의 소득의 차(불안정 지수)를 계산한다.
	int getUnstableRatio(const MaxPq& max, const MinPq& min) {
		return max.top().val - min.top().val;
	}

	//a <= x <= b 를 만족하는지 검사한다.
	bool isRanged(int a, int x, int b) {
		return a <= x && x <= b;
	}

	void test() {
		int N, K; cin >> N >> K; //N, K 입력
		vector<City> cities; //n개의 도시를 저장

		MaxPq maxPq; //cost가 최대인 City가 top에 있는 우선순위 큐
		MinPq minPq; //cost가 최소인 City가 top에 있는 우선수위 큐

		//각 도시의 소득수준을 얻는다.
		for (int i = 0; i < N; i++) {
			int cost; cin >> cost; //i번째 도시 소득 입력
			cities.push_back({ cost, i }); //City를 추가
		}

		//불안정 지수(최대, 최저소득도시의 소득차)를 구하기 위해, 첫 K 범위의 도시를 우선순위큐에 추가한다.
		for (int i = 0; i < K; i++) {
			maxPq.push(cities[i]);
			minPq.push(cities[i]);
		}

		int maxUnstableRatio = getUnstableRatio(maxPq, minPq);

		for (int i = K; i < N; i++) {
			int minRange = i - K + 1; //현재 탐색하는 범위의 최소
			int maxRange = i; //현재 탐색하는 범위의 최대

			//i번째 도시를 최대큐, 최소큐에 각각 추가한다.
			maxPq.push(cities[i]);
			minPq.push(cities[i]);

			//maxPq의 top원소의 idx가 현재 탐색하고 있는 범위 내에 들도록 조정한다.
			while (!maxPq.empty() && !isRanged(minRange, maxPq.top().idx, maxRange)) {
				maxPq.pop();
			}

			//minPq의 top원소의 idx가 현재 탐색하고 있는 범위 내에 들도록 조정한다.
			while (!minPq.empty() && !isRanged(minRange, minPq.top().idx, maxRange)) {
				minPq.pop();
			}

			//현재 탐색 범위의 불안정 지수를 계산한 뒤, 최대값이면 최대값으로 갱신한다.
			maxUnstableRatio = max(maxUnstableRatio, getUnstableRatio(maxPq, minPq));
		}
		
		//불안정 지수가 최대가 되는 값을 출력한다.
		cout << maxUnstableRatio << endl;

	}

	int main() {
		int T; cin >> T; //테스트케이스 T
		while (T--) test(); //T회만큼 프로그램 반복

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
//int main() { return week10_unstable_area::main(); }

/*
	>> input
1
7 3
10 2 5 3 7 9 1
	<< output
8
*/