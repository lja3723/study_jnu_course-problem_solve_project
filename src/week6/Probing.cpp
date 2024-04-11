//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

namespace week6_Probing {

	int getLuckyNumber(vector<bool>& pool, int N, int id) {
		int seed = id % N; //id를 이용해 최초의 시드를 추출

		//시드에 해당하는 추첨권 번호가 발급이 되어있는 경우
		//시드게 해당하는 추첨권 번호가 발급이안 된 상태일 때까지 본문 반복한다.
		while (pool[seed]) {
			//시드를 1 증가 시킴
			//만약 1 증가된 것이 N이라면 N으로 나눈 나머지를 취해
			//seed가 0으로 돌아가도록 함
			seed = (seed + 1) % N;
		}

		pool[seed] = true; //시드에 해당하는 추첨권 번호가 발급되었으므로 발급되었다고 체크
		return seed;
	}

	int main() {
		int N, M; cin >> N >> M; //N, M 입력 받기

		//N장의 행운권 번호 지급 여부 배열 생성
		vector<bool> luckyNumberPool(N, false);

		for (int m = 0; m < M; m++) {
			int id; cin >> id; //회원번호 입력받기

			//해당 회원의 회원권 번호 출력
			cout << getLuckyNumber(luckyNumberPool, N, id) << endl;
		}

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
//int main() { return week6_Probing::main(); }

/*
	>> input
5000 5
2878
15092880
1
18762879
77787879
	<< output
2878
2880
1
2879
2881
*/