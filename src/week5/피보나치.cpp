//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>

using namespace std;

namespace week5_fibonacci {

	//구할 피보나치 수열의 최대의 경우
	const int MAX_FIBO = 1'000'000;

	//피보나치 수열을 저장하는 배열
	//n번째 인덱스의 값 = n번째 피보나치 수임
	//0번째 인덱스는 더미로 두고, 1, 2번쨰 인덱스에 각각
	//1, 2번째 피보나치 수열인 0, 1을 저장하였음
	//최대 100만번째 피보나치 수열을 물어볼 수 있으므로 길이를 100만 + 1(더미)로 구성함
	int fibonacci[MAX_FIBO + 1] = { 0, 0, 1, };

	//문제를 풀기 전, 피보나치 배열에 피보나치 수열이 저장되도록 초기화한다.
	void init_fibonacci() {
		//피보나치 수열 정의에 따라 n번째 피보나치 항을 n-2, n-1번째 항을 이용해 초기화한다.
		for (int i = 3; i <= MAX_FIBO; i++) {
			//n번째 피보나치 수의 값
			int fibo_n = fibonacci[i - 2] + fibonacci[i - 1];

			// 각 피보나치 수의 마지막 8자리만 필요하므로, 8자리 수가 남도록 나머지 연산을 취한다.
			fibo_n = fibo_n % 100'000'000; 

			fibonacci[i] = fibo_n; //구한 값을 배열에 저장
		}
	}

	int main() {
		init_fibonacci(); //피보나치 수열 초기화

		int T; cin >> T; //테스트케이스 수 입력
		
		//테스트를 T회 수행한다.
		while (T--) {
			int n; cin >> n; //구하고자 하는 피보나치 수의 순서 입력
			printf("%d\n", fibonacci[n]); //n번째 피보나치 수 출력
		}

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
//int main() { return week5_fibonacci::main(); }

/*
	>> input
6
1
2
3
4
5
6
	<< output
0
1
1
2
3
5

	>> input
5
999996
999997
999998
999999
1000000
	<< output
94312505
31921872
26234377
58156249
84390626
*/