//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

namespace week3_isAscent {

	bool isAscentOrdered(int N, vector<int>& student) {

		//i = 1부터 시작함으로서 배열 길이가 1인 경우 항상 참이 출력되도록 할 수 있음
		//	길이가 1인 배열은 항상 오름차순이라고 할 수 있음
		for (int i = 1; i < N; i++)
			//오름차순을 부정하는 경우이므로, false 출력
			if (student[i - 1] > student[i]) return false;
	
		return true;
	}

	int main() {
		int N;
		cin >> N;
		vector<int> student(N);
		for (int i = 0; i < N; i++)
			cin >> student[i];

		//오름차순이면 YES, 아니면 NO 출력
		printf(isAscentOrdered(N, student) ? "YES" : "NO");

		return 0;
	}

}

//int main() { week3_isAscent::main(); }

/*
	>> input
5
1 2 3 5 4
	<< output
NO
*/