//201986 �����
#include <stdio.h>
#include <iostream>

namespace week2_Ž���ϱ�1 {

	int findIndex(int data[], int n, int m) {
		for (int i = 0; i < n; i++)			
			if (data[i] == m) return i; //m ã���� �ε��� ��ȯ
		return -1; //m�� ����
	}

	int main() {
		int n, m;
		int* data;

		scanf("%d %d", &n, &m);
		data = new int[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &data[i]);

		int answer = findIndex(data, n, m);
		printf("%d\n", answer);
		delete[] data;
		return 0;
	}

}

/*
>> input
3 2
2 3 1
<< output
0

>> input
10 4
10 7 2 6 3 1 88 27 35 85
<< output
-1
*/