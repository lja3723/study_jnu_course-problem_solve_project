//소프트웨어공학과 201986 이장안

#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

namespace project_jnu1 {

	void solve(int A, int B) {
		// (1) H 구하기
		//시침과 분침을 12시 정각(즉 시침각도 == 분침각도 == 0)에 둔 뒤, 분침을 분침각도가 B가 될 때까지 움직인다.
		//그러면 시침각도가 함께 변화하는데, 이때 '분침각도가 B가 되는 때의 시침 각도'를 H 라고 부르자. 그러면 H의 범위는 0~29이다. 
		//분침이 B도 움직이면 시침은 B/12도 움직이므로, H는 다음과 같이 구할 수 있다. 이때 정수의 나누기를 활용해 소수점을 버린다.
		int H = B / 12;

		// (2) K 구하기 
		//1시간이 흐르면 시침각도는 30도가 증가한다.
		//분침각도가 B에 대한 가능한 모든 시침각도를 K라고 하면, K는 H를 기준으로 30도씩 증가한 모든 각도이다. 따라서 아래 수식이 성립한다.
		//K = H + n * 30 (n은 0 이상의 정수, 0 <= K < 360) 
		
		// (3) A가 가능한 각도인지 판단하기
		//만약 A가 가능한 어떤 K와도 일치하지 않으면, 시계의 각도가 정상이라고 할 수 없다.
		//A가 가능한 시침각도 K의 조건(H + n * 30 == A <=> A % 30 == H)을 만족하는지 확인한다.
		//A를 나눈 나머지가 30이면 A는 K로 표현할 수 있다는 의미이다.
		bool is_A_equals_K = (A % 30 == H);

		// (4) 답 구하기
		//A를 K로 취급할 수 있는지 여부에 따라 정답을 출력한다.
		cout << (is_A_equals_K ? "O" : "X") << endl;
	}

	int main() {
		int A, B;
		cin >> A >> B;

		clock_t duration = -clock(); //시간측정 시작
		solve(A, B); //문제 풀이
		duration += clock(); //시간측정 종료
		
		cout << "실행시간: " << (double(duration) / CLOCKS_PER_SEC) << "초\n";

		return 0;
	}
}

//int main() { project_jnu1::main(); }

/*
	>> input
180 0
	<< output
O

	>> input
0 180
	<< output
X

	>> input
195 180
	<< output
O
*/