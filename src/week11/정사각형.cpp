//소프트웨어공학과 201986 이장안
#include <iostream>
#include <set>
#include <vector>
#include <utility> //pair 사용 위한 선언
#include <iomanip> //setprecision 사용 위한 선언

using namespace std;

namespace week11_square {

	//2차원 점을 표현하는 클래스
	class Point {
	public:
		//xy좌표
		int x;
		int y;

		//점의 대소를 비교하는 방법
		bool operator<(const Point& rhs) const {
			if (x == rhs.x) {
				return y < rhs.y; //y좌표는 2순위 비교대상
			}
			else return x < rhs.x; //x좌표를 1순위로 비교한다.
		}

		//두 점의 거리의 제곱을 계산한다.
		long long getSquaredDist(const Point& rhs) const {
			long long dx = abs(x - rhs.x);
			long long dy = abs(y - rhs.y);
			return dx * dx + dy * dy;
		}
	};

	//set을 vector로 변환하는 함수
	vector<Point> setToVector(const set<Point>& s) {
		vector<Point> ret;
		for (const auto& e : s) ret.push_back(e);
		return ret;
	}

	void test() {
		int N; cin >> N; //좌표 수 입력
		
		set<Point> s;
		for (int i = 0; i < N; i++) {
			int x, y; cin >> x >> y; //좌표 입력받기
			s.insert({ x, y }); //좌표를 set으로 넣어 중복을 제거한다.
		}

		vector<Point> v = setToVector(s); //set을 vector로 변환

		long long maxArea = 0; //정사각형의 최대 넓이

		//좌표상의 중복되지 않은 점 중 2개를 뽑아 정사각형을 만들기를 시도해본다.
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v.size(); j++) {

				if (i == j) continue; //같은 점은 제외함
				long long area = v[i].getSquaredDist(v[j]); //두 점 거리의 제곱은 곧 정사각형 넓이가 됨
				if (maxArea > area) continue; //지역적 답이 최대값보다 작다면 건너뛰기

				//두 점의 x, y 변화량을 계산한다.
				int dx = v[j].x - v[i].x;
				int dy = v[j].y - v[i].y;

				//벡터 (dx, dy)를 90도 회전시키면 (-dy, dx)가 되므로
				//이 벡터를 기존 점과 더해주면 정사각형의 나머지 두 점을 구할 수 있다.
				Point a({ v[i].x - dy, v[i].y + dx });
				Point b({ v[j].x - dy, v[j].y + dx });

				//두 점이 set에 포함되어 있다면 v[i], v[j], a, b로 정사각형을 만들 수 있다는 뜻이다.
				//그렇지 않으면 정사각형을 만들 수 없다.
				if (s.find(a) == s.end() || s.find(b) == s.end())
					continue;

				//정사각형의 넓이의 최대값을 갱신한다.
				maxArea = max(maxArea, area);
			}
		}

		//정답을 출력한다.
		cout << fixed << setprecision(2) << (double)maxArea << endl;
	}

	int main() {
		int T; cin >> T; //테스트케이스 수 입력
		while (T--) test(); //테스트 실행
		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
//int main() { return week11_square::main(); }

/*
	>> input
2
5
0 2
2 0
2 2
0 0
1 1
10
0 0
10 10
89 76
97 79
86 84
94 87
53 14
54 27
40 15
41 28
	<< output
4.00
170.00
*/