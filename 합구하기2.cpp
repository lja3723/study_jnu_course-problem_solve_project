//201986 이장안
#include <stdio.h>
#include <iostream>

namespace week2_합구하기2 {

	void solve(int data[], int n, int p, int q) {
		int cnt = 0; //체중제한 안걸리는 사람수
		int sum = 0; //그사람들의 몸무게 총합

		for (int i = 0; i < n; i++) {
			if (data[i] <= p) { //체중제한 걸리지 않으면
				cnt++; //수 카운트
				sum += data[i]; //무게누적
			}
		}

		//답 출력
		printf("%d %d\n", cnt, sum);
		printf(sum <= q ? "YES" : "NO");
	}

	int main() {
		int n, p, q;
		int* data;

		scanf("%d %d %d", &n, &p, &q);
		data = new int[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &data[i]);

		solve(data, n, p, q);

		delete[] data;
		return 0;
	}

}

/*
>> input
10 80 500
75 50 67 84 54 67 98 85 58 90
<< output
6 371
YES
*/