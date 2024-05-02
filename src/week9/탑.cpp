//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

namespace week9_tower {

	//타워를 표현하는 구조체
	struct Tower {
		int idx; //탑의 위치(인덱스)
		int height; //탑의 높이
		int targetIdx; //내 신호를 수신하는 탑의 위치
	};

	int main() {
		int N; cin >> N; //탑의 수 입력

		vector<Tower> tower(N + 1); //i번째 인덱스에는 i번째 탑의 높이가 저장된다.
										//0번째 인덱스는 더미로 한다.

		//i번째 탑의 높이 정보를 입력받는다. 그리고 그 타워의 위치를 초기화한다.
		for (int i = 1; i <= N; i++) {
			cin >> tower[i].height; //높이 얻기
			tower[i].idx = i; //위치 초기화
		}

		stack<Tower> ableList; //현재 신호 수신 가능성이 있을 탑들의 높이정보

		for (int i = 1; i <= N; i++) {
			tower[i].targetIdx = 0; //i번째 탑 신호를 수신할 후보 (초기값은 0으로 함)

			//가능한 리스트가 비어있지 않고, 가능한 리스트 중 가장 최근의 탑의 높이가 현재 다루는 탑 높이보다 작은 경우
			//그런 탑들은 앞으로 신호를 수신받을 가능성이 없으므로 가능 리스트에서 제거한다.
			while (!ableList.empty() && ableList.top().height < tower[i].height)
				ableList.pop();
			
			//가능 리스트가 비어있지 않으면, 리스트 중 가장 최근의 탑이 곧 현재 탑의 타겟이 된다.
			if (!ableList.empty())
				tower[i].targetIdx = ableList.top().idx;

			//현재 탑을 가능 리스트에 넣는다.
			ableList.push(tower[i]);
		}

		//각 탑에 대해 내 신호를 수신하는 탑의 위치를 출력한다.
		for (int i = 1; i <= N; i++) {
			cout << tower[i].targetIdx << " ";
		}

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
//int main() { return week9_tower::main(); }

/*
	>> input
5
6 9 5 7 4
	<< output
0 0 2 2 4
*/

//    @
//    @
//    @     @
// @  @     @
// @  @  @  @  
// @  @  @  @  @
// @  @  @  @  @
// @  @  @  @  @
// @  @  @  @  @
//---------------
// 6  9  5  7  4