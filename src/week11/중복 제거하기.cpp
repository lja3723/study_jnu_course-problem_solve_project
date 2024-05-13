//소프트웨어공학과 201986 이장안
#include <iostream>
#include <set>
using namespace std;

namespace week11_remove_duplicates {

	int main() {
		int N; cin >> N; //N 입력
		set<int> s; //중복검사 위한 set

		while (N--) { //N개의 숫자 입력
			int n; cin >> n; //숫자 입력

			//n이 이미 set에 존재 == 이미 등장한 수
			if (s.find(n) != s.end()) {
				cout << "DUPLICATED\n";
			}
			//처음 등장했으므로 set에 추가
			else {
				s.insert(n);
				cout << "OK\n";
			}
		}

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
//int main() { return week11_remove_duplicates::main(); }

/*
	>> input
5
5
3
5
3
2
	<< output
OK
OK
DUPLICATED
DUPLICATED
OK
*/