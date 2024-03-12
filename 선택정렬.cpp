//201986 �����
#include <cstdio>
#include <iostream>

using namespace std;

namespace week2_�������� {

	int getMinIndexInRange(int data[], int n, int begin, int end) {
		int minIdx = begin; //�ּҰ��� �ε����� ù ������ �ʱ�ȭ
		
		//begin�� end�� ������ break
		while (begin <= end) {
			if (data[begin] < data[minIdx]) //�� �ּҰ� �߰��ϸ�
				minIdx = begin; //�ּҰ��� �ε��� ����
			begin++;
		}
		return minIdx;
	}

	void selectionSort(int data[], int n) {
		for (int i = 0; i < n; i++) {
			int minIndex = getMinIndexInRange(data, n, i, n - 1);

			//ã�� �ּҰ��� i�� swap
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

//int main() { week2_��������::main(); }

/*
	>> input
5
3 5 1 2 4
	<< output
1 2 3 4 5
*/