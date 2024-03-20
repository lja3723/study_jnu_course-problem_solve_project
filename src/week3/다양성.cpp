//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

namespace week3_variety {

	int countUnique(int N, vector<int>& data) {
		int ret = 1; //서로 다른 자료의 개수
		for (int i = 1; i < N; i++)
			//자료가 오름차순이므로, 아래 조건을 만족한다면 오른쪽 자료는 지금까지와는 다른 자료임을 의미함
			if (data[i - 1] < data[i]) ret++;

		return ret;
	}

	int main() {
		int N;
		cin >> N;
		vector<int> data(N);

		for (int i = 0; i < N; i++)
			cin >> data[i];

		cout << countUnique(N, data);

		return 0;
	}

}

//int main() { week3_variety::main(); }

/*
	>> input
5
1 2 3 4 5
	<< output
5

	>> input
5
1 2 3 4 4
	<< output
4

	>> input
5
-1 -1 -1 -1 -1
	<< output
1
*/