//201986 이장안
#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

namespace week2_탐색하기3 {

	int findIndex(int data[], int n) {
		int sum = 0; //평균 구하기 위해 데이터 누적
		for (int i = 0; i < n; i++)
			sum += data[i];
		double avg = (double)sum / n; //평균 계산

		int idx = 0; //평균까지 거리가 가장 가까운 수의 인덱스
		double dist = 2e9; //평균까지 거리의 최소를 최대값으로 설정
		for (int i = 0; i < n; i++) {
			double d = abs(avg - data[i]); //평균까지 거리
			if (d < dist) { //새로운 최소값 발견
				dist = d; //최소값 업데이트
				idx = i; //인덱스 업데이트
			}
		}

		return idx + 1; //찾은 인덱스 리턴
	}

	int main() {
		int n;
		int* data;

		scanf("%d", &n);
		data = new int[n];

		for (int i = 0; i < n; i++)
			scanf("%d", &data[i]);

		int index = findIndex(data, n);
		printf("%d %d\n", data[index - 1], index);

		delete[] data;
		return 0;
	}

}

//int main() { week2_탐색하기3::main(); }

/*
	>> input
6
1 2 4 7 10 15
	<< output
4 7
*/