//201986 �����
#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

namespace week2_Ž���ϱ�3 {

	int findIndex(int data[], int n) {
		int sum = 0; //��� ���ϱ� ���� ������ ����
		for (int i = 0; i < n; i++)
			sum += data[i];
		double avg = (double)sum / n; //��� ���

		int idx = 0; //��ձ��� �Ÿ��� ���� ����� ���� �ε���
		double dist = 2e9; //��ձ��� �Ÿ��� �ּҸ� �ִ밪���� ����
		for (int i = 0; i < n; i++) {
			double d = abs(avg - data[i]); //��ձ��� �Ÿ�
			if (d < dist) { //���ο� �ּҰ� �߰�
				dist = d; //�ּҰ� ������Ʈ
				idx = i; //�ε��� ������Ʈ
			}
		}

		//ã�� �ε��� ���
		printf("%d ", idx + 1);
		return data[idx]; //�ش� �� ����
	}

	int main() {
		int n;
		int* data;

		scanf("%d", &n);
		data = new int[n];

		for (int i = 0; i < n; i++)
			scanf("%d", &data[i]);

		int answer = findIndex(data, n);
		printf("%d\n", answer);

		delete[] data;
		return 0;
	}

}

/*
>> input
6
1 2 4 7 10 15
<< output
4 7
*/