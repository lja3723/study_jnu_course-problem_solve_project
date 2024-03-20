//201986 �����
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

namespace week2_search2 {

	void printIndexes(string school[], int n) {
		int first = -1;
		int last = -1;

		for (int i = 0; i < n; i++) {
			//AJOU�� �ƴϸ� �ǳʶٱ�
			if (school[i] != "AJOU") continue;

			//AJOU�� ���
			if (first == -1) //ó�� ������ AJOU
				first = last = i + 1; //�� �� ���ÿ� �ʱ�ȭ
			else //AJOU�� 2�� �̻� ���� ��� last�� ������Ʈ
				last = i + 1; 
		}

		printf("%d %d\n", first, last);
	}

	int main() {
		int n;
		char buff[11];
		string* school;

		scanf("%d", &n);
		school = new string[n];

		for (int i = 0; i < n; i++) {
			scanf("%s", buff);
			school[i] = buff;
		}

		printIndexes(school, n);
		delete[] school;
		return 0;
	}

}

//int main() { week2_search2::main(); }

/*
	>> input
10
HELL
CHOSUN
SKK
KOREA
AJOU
YONSEI
SEOUL
AJOU
AJOU
WOOSONG
	<< output
5 9
*/