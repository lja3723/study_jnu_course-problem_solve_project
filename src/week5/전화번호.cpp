//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>

using namespace std;

namespace week5_tel_number {

	//전화번호의 한계 바운더리 (10000 미만이어야 함)
	#define NUM_MAX 10000

	// 뒷 전화번호 0000~9999 각각의 등장 빈도수(frequency)를 카운팅할 배열
	// 10000개의 전화번호의 등장 빈도를 카운트하므로, 길이가 10000인 배열 선언 필요
	int telnum_freq[NUM_MAX] = { 0 }; // 배열을 모두 0으로 초기화

	int main() {
		int N; cin >> N; //전화번호 수 N 입력 받기

		for (int i = 0; i < N; i++) {
			int num; cin >> num; //전화번호 뒷자리 입력 받기

			// 인덱스가 전화번호 뒷자리인 배열 공간을 증가
			// 이렇게 하면 입력받은 전화번호가 몇 번 등장했는지 카운팅이 가능
			telnum_freq[num]++; 
		}

		// 가장 잦은 빈도수를 가진 전화번호 저장 변수
		int max_telnum = 0; //맨 앞의 전화번호로 초기치 설정

		//빈도수 배열을 탐색하면서 가장 빈도가 큰 전화번호를 탐색해 나감
		for (int i = 0; i < NUM_MAX; i++)
			if (telnum_freq[i] > telnum_freq[max_telnum])
				max_telnum = i;

		//찾은 문제의 답을 형식에 맞게 출력
		printf("%04d", max_telnum);

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
//int main() { return week5_tel_number::main(); }

/*
	>> input
3
1234
4321
1234
	<< output
1234

	>> input
2
4321
1234
	<< output
1234
*/