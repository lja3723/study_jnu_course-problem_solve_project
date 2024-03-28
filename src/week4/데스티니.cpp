//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
namespace week4_destiny {

	//���� x�� ���� x^2�� ����Ѵ�.
	int square(int x) { return x * x; }

	//2���� ���� ǥ���ϴ� Ŭ�����̴�.
	class Point2D {
		int x, y; //2���� ���� ��ǥ; x��ǥ�� y��ǥ�̴�.

	public:
		//(x, y) ��ġ�� ������ ������ ��ü�� �ʱ�ȭ�Ѵ�.
		Point2D(int x = 0, int y = 0) {
			this->x = x;
			this->y = y;
		}

		//�ڱ� �ڽ�(this)��, ���ڷ� ���� �� �ٸ� ��(t) ������ �Ÿ��� ������ ����Ѵ�.
		int getSquaredDistTo(const Point2D& t) const {
			//��Ÿ��� ��Ģ(a^2 + b^2 = c^2)�� �̿��� �Ÿ� ������ �̿���, �䱸�Ǵ� ���� ����Ѵ�.
			return square(t.x - x) + square(t.y - y);
		}

		//�ڱ� �ڽ�(this)��, ���ڷ� ���� �� �ٸ� ��(t) ������ �Ÿ��� ����Ѵ�.
		double getDist(const Point2D& t) const {
			//���� �Ÿ��� ������ �������� ����� �ȴ�.
			return sqrt((double)getSquaredDistTo(t));
		}
	};


	int main() {
		int N; cin >> N; //���� ������ �Է��Ѵ�.
		vector<Point2D> points; //���� ���� �����̳� ����
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y; //���� ��ǥ�� ���� ��
			points.push_back({ x, y }); //���� �����̳ʿ� �߰��Ѵ�.
		}

		int min_sqd = INT_MAX; //������ �Ÿ�(squared distance)�� �ּڰ�. int�� max�� �ʱ�ȭ�Ѵ�.
		int min_cnt = 0; //������ �Ÿ��� �ּڰ��� ������ ���� ���� ������ �����Ѵ�.

		//N���� ������ 2���� ���� �����ϴ� ��� ������ ��츦 ���� for������ Ž���Ѵ�.
		// i != j �� �� (i, j) �� (j, i)�� �����ϰ� ����Ѵ�.
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				//���õ� �� �� i, �� j�� �Ÿ��� ����(squared distance)�� ���Ѵ�.
				int sqd = points[i].getSquaredDistTo(points[j]);

				//�� �Ÿ��� �ּҰ��� ���
				if (sqd < min_sqd) {
					min_sqd = sqd; //�ּҰ��� ������Ʈ �԰� ���ÿ�
					min_cnt = 1; //ī��Ʈ�� �ʱ�ȭ�Ѵ�. �ֳ��ϸ� ������ ������ �� �̻� �ּҰ��� ���� ī��Ʈ�� �ƴϰ� �Ǳ� ����
				}
				else if (sqd == min_sqd) {
					//������ �ּҰ��� ������ ���ο� �� ���� �߰������Ƿ�, ī��Ʈ�� 1 �����Ѵ�.
					min_cnt++;
				}
			}
		}

		//�������� �䱸�ϴ� ���� ����Ѵ�.
		printf("%.1lf\n", sqrt(min_sqd));
		printf("%d\n", min_cnt);

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�. (�ּ� ���� �� ����)
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