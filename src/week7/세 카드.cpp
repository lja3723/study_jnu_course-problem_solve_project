//소프트웨어공학과 201986 이장안
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace week7_three_cards {

	//cards에서 세 장을 뽑아 그 합이 m이 만들어질 수 있는지 여부를 확인한다.

	//만약 모든 경우의 수를 탐색하기 위해 카드 리스트에서 정직하게 3장을 모두 뽑았다면
	//시간복잡도는 O(N * N * N), 즉 최악의 경우 1000^3(10억)번의 연산을 수행하게 되므로 시간초과가 발생했을 것이다.

	//그러나 카드 두 장을 우선 뽑은 뒤 나머지 한 장을 카드리스트에서 '직접' 뽑는 것이 아니라,
	//그 한장을 계산으로 구한 뒤 그 계산이 맞는지 이진검색으로 탐색함으로서
	//시간복잡도를 O(N * N * log N) 으로 획기적으로 줄이는 것이 가능하다!

	bool is_m_possible(const vector<int>& cards, int m) {
		int N = cards.size(); //카드리스트 크기를 미리 저장

		//일단 카드리스트에서 카드 두 장을 순서 상관 없이 뽑는다.
		for (int i = 0; i < N; i++) {
			for (int j = i; j < N; j++) {

				//그리고 나머지 한 장의 카드 third의 값은 m을 이용하여 계산한다.
				int third = m - cards[i] - cards[j];

				//third가 진짜 카드리스트에 존재하는지 확인한 후, 있다면 m은 가능한 당첨번호라는 의미이다.
				if (binary_search(cards.begin(), cards.end(), third))
					return true;
			}
			//가능한 조합을 발견할 때까지 모든 경우의 수를 탐색한다.
		}		

		//모든 경우를 탐색했는데도 m을 만들 수 있는 조합은 발견되지 않은 경우다.
		return false;
	}

	int main() {
		int N, M; cin >> N >> M; // N, M을 입력 받음

		vector<int> cards(N), mlist(M);
		for (int i = 0; i < N; i++) cin >> cards[i]; //뽑을 수 있는 카드 종류를 저장한다.
		for (int i = 0; i < M; i++) cin >> mlist[i]; //가능한 당첨번호를 저장한다.

		sort(cards.begin(), cards.end()); //cards를 오름차순으로 정렬한다.
		sort(mlist.begin(), mlist.end()); //mlist를 오름차순으로 정렬한다.

		vector<int> answer; //만들어질 수 있는 M이 담길 배열

		//모든 M에 대하여 가능한 m들을 answer에 저장한다.
		for (int m = 0; m < M; m++) {
			//m이 세 장의 카드의 합으로 만들어 질 수 있으면 answer에 추가한다.
			if (is_m_possible(cards, mlist[m]))
				answer.push_back(mlist[m]);
		}

		//가능한 m이 하나도 없는 경우; NO를 출력하고 프로그램을 종료한다.
		if (answer.empty()) {
			cout << "NO";
			return 0;
		}

		//가능한 모든 m의 리스트를 공백으로 구분하여 한 줄에 출력한다.
		//앞서 mlist는 오름차순 정렬된 배열이므로, answer도 오름차순으로 정렬되어 있음을 보장할 수 있다.
		for_each(answer.begin(), answer.end(), [](int e) { cout << e << " "; });

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
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