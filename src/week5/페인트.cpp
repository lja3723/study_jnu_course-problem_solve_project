//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>

using namespace std;

namespace week5_paint {

	//좌석의 최대 수
	#define SEAT_MAX 1000

	//좌석의 색을 저장하는 배열
	//문제에서 등장 가능한 최대 범위의 크기(1000)로 지정한다.
	//이 때 좌석의 범위는 1부터 시작하므로, 0번째 인덱스를 더미로 사용하기 위해
	//최댓값 + 1 만큼의 배열 크기를 지정한다.
	//그러면 배열의 인덱스가 곧 좌석의 번호와 일치하게 된다.
	int seat[SEAT_MAX + 1]; //전역 범위이므로 0으로 초기화된다.

	//색상의 최대 가짓수
	#define COLOR_MAX 100

	//색상의 빈도수를 저장하는 배열
	int color_freq[COLOR_MAX];

	int main() {
		//좌석의 수와 색칠할 방법 수를 입력받음
		int N, M; cin >> N >> M; 

		//M가지 방법으로 좌석을 색칠해 나간다.
		while (M--) {
			//색칠 범위와 색상을 입력받는다.
			int left, right, color;
			cin >> left >> right >> color;

			//지정된 범위와 색상으로 좌석을 칠한다.
			for (int c = left; c <= right; c++)
				seat[c] = color;
		}

		//색상의 각 빈도수를 구한다.
		for (int i = 1; i <= N; i++) {
			int color = seat[i]; //i번째 좌석의 색상
			color_freq[color]++; //해당 색상의 빈도수를 1 증가시킨다.
		}


		//가장 빈번히 등장한 색상과 가장 적게 등장한 색상을 구한다.
		//두 색상을 우선 첫 번째 좌석의 색으로 초기화한다.
		int max_freq_color = seat[1]; //가장 빈번히 등장한 색상
		int min_freq_color = seat[1]; //가장 저게 등장한 색상
		for (int i = 0; i < COLOR_MAX; i++) {
			//어떤 좌석에도 칠해지지 않은 색상이라면 고려 대상이 아니므로 제외한다.
			if (color_freq[i] == 0)
				continue;

			//가장 빈번한 빈도의 색과, 가장 적은 빈도의 색을 각각 구한다.
			if (color_freq[i] > color_freq[max_freq_color])
				max_freq_color = i;
			if (color_freq[i] < color_freq[min_freq_color])
				min_freq_color = i;
		}

		//문제의 정답을 양식에 맞게 출력한다.
		cout << max_freq_color << endl << min_freq_color;

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
//int main() { return week5_paint::main(); }

/*
	>> input
10 2
2 5 1
4 7 2
	<< output
0
1

	>> input
10 2
1 9 5
2 10 5
	<< output
5
5
*/