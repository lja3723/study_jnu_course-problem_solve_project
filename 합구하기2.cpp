//201986 �����
#include <stdio.h>
#include <iostream>

namespace week2_�ձ��ϱ�2 {

	void solve(int data[], int n, int p, int q) {
		int cnt = 0; //ü������ �Ȱɸ��� �����
		int sum = 0; //�׻������ ������ ����

		for (int i = 0; i < n; i++) {
			if (data[i] <= p) { //ü������ �ɸ��� ������
				cnt++; //�� ī��Ʈ
				sum += data[i]; //���Դ���
			}
		}

		//�� ���
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