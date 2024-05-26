//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

namespace week12_mayor_recommendation {

	int main() {
		int N; cin >> N; //N �Է�

		//������ Ǯ�� ���� Ű(�̸�)�� string�̰� ��(�󵵼�, ��÷�� ��)�� int �� ����
		map<string, int> m;
		
		//�ִ� �󵵼��� �����ϴ� ������ �����Ѵ�.
		int freq_max = 0;

		while (N--) {
			string name; cin >> name; //�ĺ��� �̸� �Է�
			m[name]++; //�ĺ��� �̸��� ������ �󵵼��� 1 ������Ų��.

			//��� ���� �ĺ��� �󵵼��� �ִ밪�̸� �ִ밪�� �����Ѵ�.
			freq_max = max(freq_max, m[name]);
		}

		//������ ����Ѵ�.
		cout << freq_max << endl; //�ִ� ��ǥ��
		for (const auto& elem : m) {
			//�̸��� �����Ǵ� �󵵼��� �ռ� ���� freq_max�� ��ġ�ϸ�, �� �̸��� ����Ѵ�.
			//map�� ��ü������ ��ȸ�ϸ� Ű ������������ ��ȸ�ǹǷ�, �� �̸� ������������ ����� ����� �� �ִ�.
			if (elem.second == freq_max)
				cout << elem.first << " ";
		}

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
//int main() { return week12_mayor_recommendation::main(); }

/*
	>> input
5
DO
DO
HI
HI
BYE
	<< output
2
DO HI
*/