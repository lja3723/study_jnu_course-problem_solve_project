//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

namespace week6_counting_prime_numbers {

	//문제에서 등장 가능한 최대 범위의 정수
	const int RANGE_MAX = 1'000'000;

	//프라임 여부를 저장하는 배열.
	// isPrime[n] 이 참이면 n은 소수, 아니면 소수가 아님
	//초기치로 모든 수가 소수(true)라고 가정
	vector<bool> isPrime(RANGE_MAX + 1, true);
	
	//에라토스테네스의 체 알고리즘을 이용해 isPrime 벡터를 초기화하는 함수
	void init_using_sieve_of_Eratosthenes() {
		isPrime[1] = false; //1은 소수가 아니므로 제거한다.

		//p의 제곱근이 RANGE_MAX의 이하인 동안 반복한다.
		for (int p = 2; p * p <= RANGE_MAX; p++) {
			if (!isPrime[p]) //p가 소수라면 다음 p를 탐색하기 위해 건너뛴다.
				continue;

			//p가 소수이므로, 2 * p부터 시작해 p의 배수를 RANGE_MAX까지 모두
			//소수가 아니라고 체크한다.
			for (int i = 2 * p; i <= RANGE_MAX; i += p) {
				isPrime[i] = false;
			}
		}
	}

	int main() {
		//문제풀이 전, 소수 목록을 에라토스테네스의 체를 이용해 초기화한다.
		init_using_sieve_of_Eratosthenes();

		//테스트케이스를 입력받는다.
		int T; cin >> T;

		//테스트케이스 횟수만큼 수행한다.
		for (int t = 1; t <= T; t++) {
			int L, R; cin >> L >> R; //소수 개수를 셀 범위 L, R을 입력받는다.
			int count = 0; //소수 개수를 저장할 변수를 선언한다.

			//L부터 시작해 R까지 갈 때까지 k를 1씩 증가시킨다.
			for (int k = L; k <= R; k++)
				if (isPrime[k]) //k가 소수면 개수를 1 증가시킨다.
					count++;

			//테스트케이스에 대한 정답을 출력한다.
			cout << "Case #" << t << ":\n";
			cout << count << endl;
		}

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
//int main() { return week6_counting_prime_numbers::main(); }

/*
	>> input
3
2 10
50 100
100 1000
	<< output
Case #1:
4
Case #2:
10
Case #3:
143

	>> input
10
1 1000000
1 1000000
1 1000000
1 1000000
1 1000000
1 1000000
1 1000000
1 1000000
1 1000000
1 1000000
	<< output
Case #1:
78498
Case #2:
78498
Case #3:
78498
Case #4:
78498
Case #5:
78498
Case #6:
78498
Case #7:
78498
Case #8:
78498
Case #9:
78498
Case #10:
78498
*/