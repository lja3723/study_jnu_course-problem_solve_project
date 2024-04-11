//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>

using namespace std;

namespace week6_sudoku {

	void unitTest(int tcase) {
		int n; cin >> n; //1~81 사이 정수 입력받기

		int row = ((n - 1) / 9) + 1; //n이 몇번째 행인지 계산
		int col = ((n - 1) % 9) + 1; //n이 몇번째 열인지 계산
		int group = 3 * ((row - 1) / 3) + ((col - 1) / 3) + 1; //n이 몇 번째 그룹인지 계산

		//구한 행, 열, 그룹 출력
		cout << "Case #" << tcase << ":";
		cout << row << " " << col << " " << group << endl;
 	}

	int main() {
		//테스트케이스 수 입력 받은 뒤, 테스트케이스 수 만큼 유닛테스트를 실행한다.
		int T; cin >> T;
		for (int t = 1; t <= T; t++)
			unitTest(t);
		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
//int main() { return week6_sudoku::main(); }

/*
	>> input
5
1
2
3
4
5
	<< output
Case #1:
1 1 1
Case #2:
1 2 1
Case #3:
1 3 1
Case #4:
1 4 2
Case #5:
1 5 2
*/