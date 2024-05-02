//소프트웨어공학과 201986 이장안
#include <iostream>
#include <stack>

using namespace std;

namespace week9_bracket_string {

	bool is_vps(const string& str) {
		stack<char> st; //str이 vps인지 확인하기 위해 스택을 선언한다.

		//str의 문라를 차례대로 검사한다.
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') //열린 괄호라면 스택에 넣고,
				st.push('(');
			else if (str[i] == ')') { //닫힌 괄호면 스택에서 하나 뺀다.
				if (st.empty())
					return false; //그런데 스택이 빈 상태인 경우 vps가 아니므로 false 반환
				st.pop(); //안 비어있으면 스택의 원소를 뺀다.
			}
		}

		return st.empty(); //모든 연산을 완료 후 스택이 비어있으면 vps이고, 아니면 vps가 아니다.
	}

	int main() {
		int T; cin >> T; //테스트케이스 수

		//테스트케이스 수 만큼 반복한다.
		while (T--) {
			string s; cin >> s; //vps인지 확인할 문자열을 입력받는다.

			//vps이면 YES, 아니면 NO를 출력한다.
			cout << (is_vps(s) ? "YES" : "NO") << endl;
		}

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
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