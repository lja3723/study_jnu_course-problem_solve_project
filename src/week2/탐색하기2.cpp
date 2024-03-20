//201986 이장안
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

namespace week2_search2 {

	void printIndexes(string school[], int n) {
		int first = -1;
		int last = -1;

		for (int i = 0; i < n; i++) {
			//AJOU가 아니면 건너뛰기
			if (school[i] != "AJOU") continue;

			//AJOU인 경우
			if (first == -1) //처음 만나는 AJOU
				first = last = i + 1; //두 값 동시에 초기화
			else //AJOU를 2번 이상 보는 경우 last만 업데이트
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