//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

namespace week5_application {

	//시리얼넘버의 최댓값
	#define SERIAL_MAX 100000

	//시리얼넘버의 등장 빈도수를 구하는 배열
	vector<int> serial_freq(SERIAL_MAX + 1);

	int main() {
		int N; cin >> N; //데이터의 수 입력
		
		//데이터를 입력받고, 시리얼넘버의 빈도수를 측정한다.
		while (N--) {
			int serial; cin >> serial; //시리얼 넘버 입력받기

			//해당 시리얼넘버의 빈도수를 1 증가한다.
			serial_freq[serial]++;
		}
		
		//문제의 정답을 양식에 맞게 출력한다.
		for (int serial = 1; serial <= SERIAL_MAX; serial++) {
			if (serial_freq[serial] == 1) //딱 한번만 등장한 시리얼 번호들만 순서대로 출력한다.
				cout << serial << " ";
		}

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
//int main() { return week5_application::main(); }

/*
	>> input
6
2 3 3 4 7 5
	<< output
2 4 5 7
*/