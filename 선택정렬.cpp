//201986 이장안
#include <cstdio>
#include <iostream>

using namespace std;

namespace week2_선택정렬 {

	int getMinIndexInRange(int data[], int n, int begin, int end) {
		int minIdx = begin; //최소값의 인덱스를 첫 값으로 초기화
		
		//begin이 end를 넘으면 break
		while (begin <= end) {
			if (data[begin] < data[minIdx]) //새 최소값 발견하면
				minIdx = begin; //최소값의 인덱스 갱신
			begin++;
		}
		return minIdx;
	}

	void selectionSort(int data[], int n) {
		for (int i = 0; i < n; i++) {
			int minIndex = getMinIndexInRange(data, n, i, n - 1);

			//찾은 최소값과 i를 swap
			int tmp = data[minIndex];
			data[minIndex] = data[i];
			data[i] = tmp;
		}
	}

	int main() {
		int n;
		int* data;

		scanf("%d", &n);
		data = new int[n];

		for (int i = 0; i < n; i++)
			scanf("%d", &data[i]);

		selectionSort(data, n);

		for (int i = 0; i < n; i++)
			printf(i > 0 ? " %d" : "%d", data[i]);

		delete[] data;
		return 0;
	}

}

//int main() { week2_선택정렬::main(); }

/*
	>> input
5
3 5 1 2 4
	<< output
1 2 3 4 5
*/