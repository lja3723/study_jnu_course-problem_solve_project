//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

namespace week4_constant_driving {

	int max(int a, int b) { return a > b ? a : b; } //a, b 중 더 큰 쪽을 반환한다.
	int min(int a, int b) { return a > b ? b : a; } //a, b 중 더 작은 쪽을 반환한다.

	bool isConsecutive(int n) {
		int max_data = 0; //입력된 데이터 중 가장 큰 데이터를 저장한다. 초기치로 가능한 최솟값을 저장한다.
		int min_data = 1'000'000; //입력된 데이터 중 가장 작 데이터를 저장한다. 초기치로 가능한 최댓값을 저장한다.

		//n개의 데이터를 입력받고 최댓값, 최솟값을 갱신한다.
		for (int i = 0; i < n; i++) {
			int data; cin >> data; //데이터를 1개 입력받는다.
			max_data = max(max_data, data); //최댓값을 갱신한다.
			min_data = min(min_data, data); //최솟값을 갱신한다.
		}

		//입력된 모든 수열이 1씩 증가하는 수열이라면, 최솟값과 최댓값의 차이는 입력된 데이터 수 n보다 하나 클 것이다.
		//그렇지 않으면 항상 1씩 증가하는 수열이 아니라는 의미가 된다.
		return max_data - min_data + 1 == n;
	}

	int main() {
		//입력받는 데이터 수 n을 받는다.
		int n; cin >> n;

		//n개의 데이터를 입력받고, 그 데이터가 1씩 증가하는 수열이라면 YES, 아니면 NO를 출력한다.
		cout << (isConsecutive(n) ? "YES" : "NO");

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다. (주석 해제 후 실행)
//int main() { return week4_constant_driving::main(); }

/*
	>> input
5
1 2 5 3 4
	<< output
YES

	>> input
5
1 2 6 3 4
	<< output
NO
*/