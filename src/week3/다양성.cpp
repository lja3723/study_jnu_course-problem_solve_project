//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

namespace week3_variety {

	int countUnique(int N, vector<int>& data) {
		int ret = 1; //���� �ٸ� �ڷ��� ����
		for (int i = 1; i < N; i++)
			//�ڷᰡ ���������̹Ƿ�, �Ʒ� ������ �����Ѵٸ� ������ �ڷ�� ���ݱ����ʹ� �ٸ� �ڷ����� �ǹ���
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