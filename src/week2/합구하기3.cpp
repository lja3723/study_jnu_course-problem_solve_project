//201986 이장안
#include <cstdio>
#include <iostream>

using namespace std;

namespace week2_getSum3 {

	// 1 ~ n 합 공식 계산값 리턴
	int getRangeSumFromOne(int i) {
		return i * (i + 1) / 2;
	}

	long long getAnswer(int N) {
		long long ret = 0;
		//1부터 N까지의 (1~N 합) 값을 누적함
		for (int i = 1; i <= N; i++)
			ret += getRangeSumFromOne(i);
		return ret;
	}

	int main() {
		int n;
		scanf("%d", &n);

		long long answer = getAnswer(n);
		printf("%lld\n", answer);
		return 0;
	}

}

//int main() { week2_getSum3::main(); }

/*
	>> input
100
	<< output
171700
*/