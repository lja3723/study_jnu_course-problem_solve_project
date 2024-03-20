//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

namespace week3_compareString {

	const int MAX_LEN = 100'000; //최대 길이 10만

	class MyString {
	private:
		char* str;
		int length;

	public:
		MyString(const char* str) {
			length = strnlen(str, MAX_LEN);
			this->str = new char[length + 1]; // '\0'로 끝나기 위해 +1 공간 마련
			for (int i = 0; i < length; i++)
				this->str[i] = str[i];
			this->str[length] = '\0'; // '\0'으로 끝나는 문자열
		}

		MyString(const string& origin) {
			length = origin.length();
			str = new char[length + 1]; // '\0'로 끝나기 위해 +1 공간 마련
			for (int i = 0; i < length; i++)
				str[i] = origin[i];
			str[length] = '\0'; // '\0'으로 끝나는 문자열
		}

		~MyString() {
			delete[] str;
		}

		bool operator<(const MyString& o) const {
			int n = min(length, o.length);

			for (int i = 0; i < n; i++) {
				//i번째 문자가 다른 경우 일치하지 않은 것이다.
				if (str[i] != o.str[i])
					//아래의 비교식 결과를 곧바로 리턴하면 된다.
					//결과가 true인 경우: 말 그대로 '<' 조건 만족이므로 메서드 반환값은 참이다.
					//결과가 false인 경우: '>' 조건을 만족하는 것이므로, 메서드 반환값은 거짓이다.
					return str[i] < o.str[i];
			}

			//0 ~ n-1까지 결과가 같으므로 두 문자열의 길이만 비교하면 대소관계를 파악할 수 있으며,
			//아래의 비교식 결과를 곧바로 리턴하면 된다.
			//결과가 true인 경우: 말 그대로 '<' 조건을 만족하므로(algo < algorithm 인 경우) 메서드 반환값은 참이다.
			//그렇지 않으면 메서드 반환값은 거짓이다.
			return length < o.length;
		}

		bool operator>(const MyString& o) const {
			int n = min(length, o.length);

			for (int i = 0; i < n; i++) {
				//i번째 문자가 다른 경우 일치하지 않은 것이다.
				if (str[i] != o.str[i])
					//아래의 비교식 결과를 곧바로 리턴하면 된다.
					//결과가 true인 경우: 말 그대로 '>' 조건 만족이므로 메서드 반환값은 참이다.
					//결과가 false인 경우: '<' 조건을 만족하는 것이므로, 메서드 반환값은 거짓이다.
					return str[i] > o.str[i];
			}

			//0 ~ n-1까지 결과가 같으므로 두 문자열의 길이만 비교하면 대소관계를 파악할 수 있으며,
			//아래의 비교식 결과를 곧바로 리턴하면 된다.
			//결과가 true인 경우: 말 그대로 '>' 조건을 만족하므로(algorithm > algo 인 경우) 메서드 반환값은 참이다.
			//그렇지 않으면 메서드 반환값은 거짓이다.
			return length > o.length;
		}

		bool operator==(const MyString& o) const {
			// '<' 도 아니고 '>' 도 아닌 경우, 두 문자열은 같다.
			return !(*this < o) && !(*this > o);
		}
	};

	int main() {
		string s1, s2;
		cin >> s1 >> s2;

		MyString mys1(s1), mys2(s2);

		if (mys1 < mys2)
			printf("-1");
		else if (mys1 > mys2)
			printf("1");
		else if (mys1 == mys2)
			printf("0");
		else
			printf("something wrong...");

		return 0;
	}

}

//int main() { week3_compareString::main(); }

/*
	>> input
algorithm
allergy
	<< output
-1

	>> input
algorithm
algorithm
	<< output
0

	>> input
allergy
algorithm
	<< output
1
*/