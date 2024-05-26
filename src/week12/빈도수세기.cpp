//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

namespace week12_counting_frequency {

	int main() {
		int N; cin >> N; //N을 입력받는다.

		//키: 등장한 정수
		//값: 그 정수의 등장 횟수
		map<int, int> m;

		while (N--) {
			int i; cin >> i; //i번째 수를 입력받는다.

			// i를 키값으로 하여, 이에 대응하는 변수를 1 증가시킨다.
			// [] 연산자의 동작은 1. i에 대응하는 키가 있는 경우, 2. i에 대응하는 키가 없는 경우로 나뉜다.
			// 1. i에 대응하는 키가 있는 경우
			//		i에 대응하는 값의 참조를 반환한다.
			//		참조에 대해 ++가 적용되어 1이 증가한다.
			// 2. i에 대응하는 키가 없는 경우
			//		우선 i키를 생성한 후 이에 대응하는 변수의 기본값(int의 경우 0)을 연결한다. 그리고 그 값의 참조를 반환한다.
			//		키 i와 int의 기본값 0이가 대응된 뒤, 하고자 하는 동작인 ++에 의해 1이 증가한다. 
			m[i]++;

			//맵의 전체 크기와 i에 대응하는 값을 출력한다.
			cout << m.size() << " " << m[i] << endl;
		}

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
//int main() { return week12_counting_frequency::main(); }

/*
	>> input
5
3
5
3
5
2
	<< output
1 1
2 1
2 2
2 2
3 1
*/