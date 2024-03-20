//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

namespace week3_compareString {

	const int MAX_LEN = 100'000; //�ִ� ���� 10��

	class MyString {
	private:
		char* str;
		int length;

	public:
		MyString(const char* str) {
			length = strnlen(str, MAX_LEN);
			this->str = new char[length + 1]; // '\0'�� ������ ���� +1 ���� ����
			for (int i = 0; i < length; i++)
				this->str[i] = str[i];
			this->str[length] = '\0'; // '\0'���� ������ ���ڿ�
		}

		MyString(const string& origin) {
			length = origin.length();
			str = new char[length + 1]; // '\0'�� ������ ���� +1 ���� ����
			for (int i = 0; i < length; i++)
				str[i] = origin[i];
			str[length] = '\0'; // '\0'���� ������ ���ڿ�
		}

		~MyString() {
			delete[] str;
		}

		bool operator<(const MyString& o) const {
			int n = min(length, o.length);

			for (int i = 0; i < n; i++) {
				//i��° ���ڰ� �ٸ� ��� ��ġ���� ���� ���̴�.
				if (str[i] != o.str[i])
					//�Ʒ��� �񱳽� ����� ��ٷ� �����ϸ� �ȴ�.
					//����� true�� ���: �� �״�� '<' ���� �����̹Ƿ� �޼��� ��ȯ���� ���̴�.
					//����� false�� ���: '>' ������ �����ϴ� ���̹Ƿ�, �޼��� ��ȯ���� �����̴�.
					return str[i] < o.str[i];
			}

			//0 ~ n-1���� ����� �����Ƿ� �� ���ڿ��� ���̸� ���ϸ� ��Ұ��踦 �ľ��� �� ������,
			//�Ʒ��� �񱳽� ����� ��ٷ� �����ϸ� �ȴ�.
			//����� true�� ���: �� �״�� '<' ������ �����ϹǷ�(algo < algorithm �� ���) �޼��� ��ȯ���� ���̴�.
			//�׷��� ������ �޼��� ��ȯ���� �����̴�.
			return length < o.length;
		}

		bool operator>(const MyString& o) const {
			int n = min(length, o.length);

			for (int i = 0; i < n; i++) {
				//i��° ���ڰ� �ٸ� ��� ��ġ���� ���� ���̴�.
				if (str[i] != o.str[i])
					//�Ʒ��� �񱳽� ����� ��ٷ� �����ϸ� �ȴ�.
					//����� true�� ���: �� �״�� '>' ���� �����̹Ƿ� �޼��� ��ȯ���� ���̴�.
					//����� false�� ���: '<' ������ �����ϴ� ���̹Ƿ�, �޼��� ��ȯ���� �����̴�.
					return str[i] > o.str[i];
			}

			//0 ~ n-1���� ����� �����Ƿ� �� ���ڿ��� ���̸� ���ϸ� ��Ұ��踦 �ľ��� �� ������,
			//�Ʒ��� �񱳽� ����� ��ٷ� �����ϸ� �ȴ�.
			//����� true�� ���: �� �״�� '>' ������ �����ϹǷ�(algorithm > algo �� ���) �޼��� ��ȯ���� ���̴�.
			//�׷��� ������ �޼��� ��ȯ���� �����̴�.
			return length > o.length;
		}

		bool operator==(const MyString& o) const {
			// '<' �� �ƴϰ� '>' �� �ƴ� ���, �� ���ڿ��� ����.
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