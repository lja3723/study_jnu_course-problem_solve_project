//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

namespace week4_prime_number_determination {

	//약수가 2개인지 판단하여, N이 소수인지 여부를 반환한다.
	bool isPrime(int N) {
		// 2 미만의 정수는 소수가 아님
		if (N < 2) return false;

		//주어진 N을 1부터 sqrt(N)까지 나눠보면 N이 소수인지 아닌지 판별 가능
		//이때 sqrt(10억)은 대략 32000이므로, 테스트케이스가 최대 10개이더라도
		//2초 안에 모든 경우에 대한 판별이 가능할 것임

		//2부터 경계값까지 N을 나눈 나머지를 확인함
		for (int n = 2; n*n <= N /* n <= sqrt(N) 와 같은 표현, 정수 연산으로 정확도 향상 */; n++)
			if (N % n == 0) return false; //나누어 떨어지면 소인수가 2개 초과했다는 뜻 -> 소수가 아님
				

		//나눠떨어진게 없으면 N 미만의 소인수가 없음 == N은 소수임
		return true;
	}

	int main() {
		//테스트케이스 수 입력
		int T; cin >> T; 

		//테스트케이스 T회 수행
		for (int i = 1; i <= T; i++) {
			//소수 판별할 정수 입력
			int n; cin >> n; 
			//테스트케이스
			cout << "Case #" << i << endl;
			//소수 여부에 따라 결과 출력
			cout << (isPrime(n) ? "YES" : "NO") << endl;
		}

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다. (주석 해제 후 실행)
//int main() { return week4_prime_number_determination::main(); }

/*
	>> input
1
5
	<< output
Case #1
YES

	>> input
2
1
5
	<< output
Case #1
No
Case #2
YES
*/