//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

namespace week3_measureHeight {

	int getTallest(int N, int M, vector<int>& height, vector<int>& month) {
		int tallest = -1; //가장 큰 도토리 키를 -1로 초기화 (생일이 M월인 도토리 없을 경우 그대로 리턴)

		for (int i = N - 1; i >= 0; i--) { //가장 뒤에서부터 탐색함
			if (month[i] == M) return height[i]; //생일이 M월인 경우 그 것이 가장 큰 키이므로 반환
		}

		return tallest;
	}

	int main() {
		int N;
		cin >> N;

		vector<int> height(N), month(N);
		for (int i = 0; i < N; i++)
			cin >> height[i]; //키 배열 입력밭기
		for (int i = 0; i < N; i++)
			cin >> month[i]; //월 배열 입력밭기

		int M;
		cin >> M;

		cout << getTallest(N, M, height, month);

		return 0;
	}

}

//int main() { week3_measureHeight::main(); }

/*
	>> input
5
12 13 14 15 16
1 5 7 2 3
2
	<< output
15

	>> input
5
12 13 14 15 16
1 5 7 2 3
12
	<< output
-1

	>> input
20
10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29
1 11 8 10 7 11 8 12 8 6 2 10 10 1 3 12 3 5 5 5
1
	<< output
23
*/