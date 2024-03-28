//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
namespace week4_destiny {

	//정수 x에 대해 x^2를 계산한다.
	int square(int x) { return x * x; }

	//2차원 점을 표현하는 클래스이다.
	class Point2D {
		int x, y; //2차원 점의 좌표; x좌표와 y좌표이다.

	public:
		//(x, y) 위치를 가지는 점으로 객체를 초기화한다.
		Point2D(int x = 0, int y = 0) {
			this->x = x;
			this->y = y;
		}

		//자기 자신(this)과, 인자로 들어온 또 다른 점(t) 사이의 거리의 제곱을 계산한다.
		int getSquaredDistTo(const Point2D& t) const {
			//피타고라스 법칙(a^2 + b^2 = c^2)을 이용한 거리 공식을 이용해, 요구되는 값을 계산한다.
			return square(t.x - x) + square(t.y - y);
		}

		//자기 자신(this)과, 인자로 들어온 또 다른 점(t) 사이의 거리를 계산한다.
		double getDist(const Point2D& t) const {
			//그저 거리의 제곱에 제곱근을 씌우면 된다.
			return sqrt((double)getSquaredDistTo(t));
		}
	};


	int main() {
		int N; cin >> N; //점의 개수를 입력한다.
		vector<Point2D> points; //점을 담을 컨테이너 선언
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y; //점의 좌표를 받은 뒤
			points.push_back({ x, y }); //점을 컨테이너에 추가한다.
		}

		int min_sqd = INT_MAX; //제곱한 거리(squared distance)의 최솟값. int의 max로 초기화한다.
		int min_cnt = 0; //제곱한 거리의 최솟값을 가지는 점의 쌍의 개수를 저장한다.

		//N개의 점에서 2개의 점을 선택하는 모든 조합의 경우를 이중 for문으로 탐색한다.
		// i != j 일 때 (i, j) 는 (j, i)와 동일하게 취급한다.
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				//선택된 두 점 i, 점 j의 거리의 제곱(squared distance)를 구한다.
				int sqd = points[i].getSquaredDistTo(points[j]);

				//그 거리가 최소값인 경우
				if (sqd < min_sqd) {
					min_sqd = sqd; //최소값을 업데이트 함과 동시에
					min_cnt = 1; //카운트를 초기화한다. 왜냐하면 기존의 정보는 더 이상 최소값에 대한 카운트가 아니게 되기 때문
				}
				else if (sqd == min_sqd) {
					//동일한 최소값을 가지는 새로운 두 쌍을 발견했으므로, 카운트를 1 증가한다.
					min_cnt++;
				}
			}
		}

		//문제에서 요구하는 답을 출력한다.
		printf("%.1lf\n", sqrt(min_sqd));
		printf("%d\n", min_cnt);

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다. (주석 해제 후 실행)
//int main() { return week4_destiny::main(); }

/*
	>> input
2
1 1
2 2
	<< output
1.4
1

	>> input
5
10000 9999
-10000 -9999
10000 -9999
-10000 9999
0 0
	<< output
14141.4
4

	>> input
5
-1 5
2 5
3 2
3 6
-1 6
	<< output
1.0
1
*/