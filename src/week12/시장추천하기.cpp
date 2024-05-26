//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

namespace week12_mayor_recommendation {

	int main() {
		int N; cin >> N; //N 입력

		//문제를 풀기 위한 키(이름)가 string이고 값(빈도수, 추첨된 수)이 int 맵 선언
		map<string, int> m;
		
		//최대 빈도수를 저장하는 변수를 선언한다.
		int freq_max = 0;

		while (N--) {
			string name; cin >> name; //후보자 이름 입력
			m[name]++; //후보자 이름이 등장한 빈도수를 1 증가시킨다.

			//방금 구한 후보자 빈도수가 최대값이면 최대값을 갱신한다.
			freq_max = max(freq_max, m[name]);
		}

		//정답을 출력한다.
		cout << freq_max << endl; //최다 득표수
		for (const auto& elem : m) {
			//이름에 대응되는 빈도수가 앞서 구한 freq_max와 일치하면, 그 이름을 출력한다.
			//map을 전체적으로 순회하면 키 오름차순으로 순회되므로, 즉 이름 오름차순으로 결과를 출력할 수 있다.
			if (elem.second == freq_max)
				cout << elem.first << " ";
		}

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
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