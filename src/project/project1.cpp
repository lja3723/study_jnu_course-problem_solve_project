//����Ʈ������а� 201986 �����

#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

namespace jnu_project1 {

	void solve(int A, int B) {
		//��ħ������ B�϶��� b���̶� ����.
		//�־��� ��ħ���� A�� �����Ǵ� 12�� ���� ��ħ������ ������. �̰��� A % 30�� ����.
		//��ħ�� ��ħ���� 12�� �����Ƿ�, ���� A, B�� ������ ������ ��쿡 A % 30�� 12�� �ϸ� ��ħ ���� B�� ��ġ�� ���̴�.
		//���� ��ġ���� �ʴ´ٸ�, �־��� A, B�� ���ʿ� �������� ���� ������� �ǹ̰� �ȴ�.
		cout << (A % 30 * 12 == B ? "O" : "X") << endl;
	}

	int main() {
		int A, B;
		cin >> A >> B;

		clock_t duration = -clock(); //�ð����� ����
		solve(A, B); //���� Ǯ��
		duration += clock(); //�ð����� ����
		
		printf("%����ð�: %.3lf��\n", double(duration) / CLOCKS_PER_SEC);

		return 0;
	}
}

//int main() { return jnu_project1::main(); }

/*
	>> input
180 0
	<< output
O

	>> input
0 180
	<< output
X

	>> input
195 180
	<< output
O
*/