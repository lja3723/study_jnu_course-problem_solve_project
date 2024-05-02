//����Ʈ������а� 201986 �����
#include <iostream>
#include <stack>

using namespace std;

namespace week9_bracket_string {

	bool is_vps(const string& str) {
		stack<char> st; //str�� vps���� Ȯ���ϱ� ���� ������ �����Ѵ�.

		//str�� ���� ���ʴ�� �˻��Ѵ�.
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') //���� ��ȣ��� ���ÿ� �ְ�,
				st.push('(');
			else if (str[i] == ')') { //���� ��ȣ�� ���ÿ��� �ϳ� ����.
				if (st.empty())
					return false; //�׷��� ������ �� ������ ��� vps�� �ƴϹǷ� false ��ȯ
				st.pop(); //�� ��������� ������ ���Ҹ� ����.
			}
		}

		return st.empty(); //��� ������ �Ϸ� �� ������ ��������� vps�̰�, �ƴϸ� vps�� �ƴϴ�.
	}

	int main() {
		int T; cin >> T; //�׽�Ʈ���̽� ��

		//�׽�Ʈ���̽� �� ��ŭ �ݺ��Ѵ�.
		while (T--) {
			string s; cin >> s; //vps���� Ȯ���� ���ڿ��� �Է¹޴´�.

			//vps�̸� YES, �ƴϸ� NO�� ����Ѵ�.
			cout << (is_vps(s) ? "YES" : "NO") << endl;
		}

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
//int main() { return week9_bracket_string::main(); }

/*
	>> input
6
(())())
(((()())()
(()())((()))
((()()(()))(((())))()
()()()(()()())()
(()((())()(
	<< output
NO
NO
YES
NO
YES
NO
*/