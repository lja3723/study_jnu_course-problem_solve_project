//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

namespace week4_constant_driving {

	int max(int a, int b) { return a > b ? a : b; } //a, b �� �� ū ���� ��ȯ�Ѵ�.
	int min(int a, int b) { return a > b ? b : a; } //a, b �� �� ���� ���� ��ȯ�Ѵ�.

	bool isConsecutive(int n) {
		int max_data = 0; //�Էµ� ������ �� ���� ū �����͸� �����Ѵ�. �ʱ�ġ�� ������ �ּڰ��� �����Ѵ�.
		int min_data = 1'000'000; //�Էµ� ������ �� ���� �� �����͸� �����Ѵ�. �ʱ�ġ�� ������ �ִ��� �����Ѵ�.

		//n���� �����͸� �Է¹ް� �ִ�, �ּڰ��� �����Ѵ�.
		for (int i = 0; i < n; i++) {
			int data; cin >> data; //�����͸� 1�� �Է¹޴´�.
			max_data = max(max_data, data); //�ִ��� �����Ѵ�.
			min_data = min(min_data, data); //�ּڰ��� �����Ѵ�.
		}

		//�Էµ� ��� ������ 1�� �����ϴ� �����̶��, �ּڰ��� �ִ��� ���̴� �Էµ� ������ �� n���� �ϳ� Ŭ ���̴�.
		//�׷��� ������ �׻� 1�� �����ϴ� ������ �ƴ϶�� �ǹ̰� �ȴ�.
		return max_data - min_data + 1 == n;
	}

	int main() {
		//�Է¹޴� ������ �� n�� �޴´�.
		int n; cin >> n;

		//n���� �����͸� �Է¹ް�, �� �����Ͱ� 1�� �����ϴ� �����̶�� YES, �ƴϸ� NO�� ����Ѵ�.
		cout << (isConsecutive(n) ? "YES" : "NO");

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�. (�ּ� ���� �� ����)
//int main() { return week4_constant_driving::main(); }

/*
	>> input
5
1 2 5 3 4
	<< output
YES

	>> input
5
1 2 6 3 4
	<< output
NO
*/