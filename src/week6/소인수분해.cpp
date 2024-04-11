//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>

using namespace std;

namespace week6_factorization {

	void testCase(int tIdx) {
		int n; cin >> n; //소인수분해할 정수 n 입력
		int tmpN = n; //n을 저장하는 임시 n
		int p = 2; //나눌 수, 처음에는 2로 시작

		//tIdx 번째 테스트케이스라는 의미
		cout << "#" << tIdx << ":\n";

		//나눌 수의 제곱근이 n 이하일 동안 반복한다.
		while (p * p <= n) {

			//p가 소인수이므로
			if (tmpN % p == 0) {
				cout << p << " "; //출력한 뒤
				tmpN /= p; //임시 n을 P로 나눈다.
			}
			//p가 소인수가 아니므로
			else {
				p++; //p를 증가시킨다.
			}
		}

		//임시 n이 1이 아니라면 소인수 분해가 완전히 완료된 것이 아니다.
		//tmpN에 저장된 수가 곧 N의 마지막 소인수(소수)라는 의미이므로,
		//그 수를 출력한다.
		if (tmpN != 1) 
			cout << tmpN;

		//소인수 분해가 완료되었으므로, 개행을 시킨다.
		cout << "\n";
	}

	int main() {
		int T; cin >> T; //테스트케이스 횟수 입력

		//각 테스트를 T회 반복
		for (int t = 1; t <= T; t++)
			testCase(t);

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
//int main() { return week6_factorization::main(); }

/*
	>> input
3
24
28
21
	<< output
#1:
2 2 2 3
#2:
2 2 7
#3:
3 7
*/