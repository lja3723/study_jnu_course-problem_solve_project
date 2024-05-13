//����Ʈ������а� 201986 �����
#include <iostream>
#include <set>
using namespace std;

namespace week11_remove_duplicates {

	int main() {
		int N; cin >> N; //N �Է�
		set<int> s; //�ߺ��˻� ���� set

		while (N--) { //N���� ���� �Է�
			int n; cin >> n; //���� �Է�

			//n�� �̹� set�� ���� == �̹� ������ ��
			if (s.find(n) != s.end()) {
				cout << "DUPLICATED\n";
			}
			//ó�� ���������Ƿ� set�� �߰�
			else {
				s.insert(n);
				cout << "OK\n";
			}
		}

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
//int main() { return week11_remove_duplicates::main(); }

/*
	>> input
5
5
3
5
3
2
	<< output
OK
OK
DUPLICATED
DUPLICATED
OK
*/