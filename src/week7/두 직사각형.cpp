//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>

using namespace std;

namespace week7_two_rectangles {

	struct Point { int x, y; }; //2차원 점을 표현하는 구조체

	struct Rect { int left, right, top, bottom; }; //직사각형을 표현하는 구조체

	//두 직사각형의 공통 넓이를 구하는 함수
	int get_cross_area(const Rect& a, const Rect& b) {
		Rect cross; //교차하는 직사각형 영역

		cross.left	 = max(a.left, b.left); //교차 직사각형의 left = 두 직사각형 left 중 더 큰 것임
		cross.right	 = min(a.right, b.right); //교차 직사각형의 right = 두 직사각형 right 중 더 작은 것임
		cross.top	 = min(a.top, b.top); //교차 직사각형의 top = 두 직사각형 top 중 더 작은 것임
		cross.bottom = max(a.bottom, b.bottom); //교차 직사각형의 bottom = 두 직사각형 bottom 중 더 큰 것임

		//right - left: 가로의 길이, 만약 값이 음수라면 0을 택한다. (max 함수의 성질을 이용)
		//top - bottom: 세로의 길이, 만약 값이 음수라면 0을 택한다. (max 함수의 성질을 이용)
		//두 값을 곱한 것이 곧 구하고자 하는 넓이이다.
		return max(0, cross.right - cross.left) * max(0, cross.top - cross.bottom);
	}
		 
	int main() {
		int T; cin >> T; //테스트케이스 수 T 입력

		while (T--) {
			//점 a, b, p, q의 좌표 정보를 입력받는다.
			Point a, b, p, q;
			cin >> a.x >> a.y >> b.x >> b.y;
			cin >> p.x >> p.y >> q.x >> q.y;

			//받은 점의 정보를 직사각형에 대한 정보(left right top bottom)로 변환한다.

			Rect ra; //점 a, b로 구성된 첫번째 직사각형 a
			ra.left		= min(a.x, b.x); //두 점의 x좌표 중 작은 것이 left
			ra.right	= max(a.x, b.x); //큰 것이 right
			ra.top		= max(a.y, b.y); //두 점의 y좌표 중 큰 것이 top
			ra.bottom	= min(a.y, b.y); //작은 것이 bottom

			Rect rb; //점 a, b로 구성된 두번째 직사각형 b
			rb.left		= min(p.x, q.x); //두 점의 x좌표 중 작은 것이 left
			rb.right	= max(p.x, q.x); //큰 것이 right
			rb.top		= max(p.y, q.y); //두 점의 y좌표 중 큰 것이 top
			rb.bottom	= min(p.y, q.y); //작은 것이 bottom

			//두 직사각형이 공통으로 교차하는 영역의 넓이를 구한다.
			cout << get_cross_area(ra, rb) << endl;
		}

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
//int main() { return week7_two_rectangles::main(); }

/*
	>> input
1
1 1 3 3 4 2 2 4
	<< output
1
*/