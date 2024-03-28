//소프트웨어공학과 201986 이장안

#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

namespace jnu_project1 {

	void solve(int A, int B) {
		//분침각도가 B일때를 b분이라 하자.
		//주어진 시침각도 A와 대응되는 12시 경의 시침각도를 구하자. 이것은 A % 30과 같다.
		//분침은 시침보다 12배 빠르므로, 각도 A, B가 가능한 각도일 경우에 A % 30을 12배 하면 분침 각도 B와 일치할 것이다.
		//만약 일치하지 않는다면, 주어진 A, B는 애초에 가능하지 않은 각도라는 의미가 된다.
		cout << (A % 30 * 12 == B ? "O" : "X") << endl;
	}

	int main() {
		int A, B;
		cin >> A >> B;

		clock_t duration = -clock(); //시간측정 시작
		solve(A, B); //문제 풀이
		duration += clock(); //시간측정 종료
		
		printf("%실행시간: %.3lf초\n", double(duration) / CLOCKS_PER_SEC);

		return 0;
	}
}

//int main() { return jnu_project1::main(); }

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