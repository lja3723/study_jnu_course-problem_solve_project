//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Point2D {
	int x, y;
};

int getSquaredDistanceTo(const Point2D& target);

namespace week4_destiny {

	void func();

	int main() {
		int N;
		cin >> N;
		vector<Point2D> v;
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			v.push_back({ x, y });
		}

		return 0;
	}

}

//int main() { return week4_destiny::main(); }

/*
	>> input
0
	<< output
0
*/