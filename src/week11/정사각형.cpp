//����Ʈ������а� 201986 �����
#include <iostream>
#include <set>
#include <vector>
#include <utility> //pair ��� ���� ����
#include <iomanip> //setprecision ��� ���� ����

using namespace std;

namespace week11_square {

	//2���� ���� ǥ���ϴ� Ŭ����
	class Point {
	public:
		//xy��ǥ
		int x;
		int y;

		//���� ��Ҹ� ���ϴ� ���
		bool operator<(const Point& rhs) const {
			if (x == rhs.x) {
				return y < rhs.y; //y��ǥ�� 2���� �񱳴��
			}
			else return x < rhs.x; //x��ǥ�� 1������ ���Ѵ�.
		}

		//�� ���� �Ÿ��� ������ ����Ѵ�.
		long long getSquaredDist(const Point& rhs) const {
			long long dx = abs(x - rhs.x);
			long long dy = abs(y - rhs.y);
			return dx * dx + dy * dy;
		}
	};

	//set�� vector�� ��ȯ�ϴ� �Լ�
	vector<Point> setToVector(const set<Point>& s) {
		vector<Point> ret;
		for (const auto& e : s) ret.push_back(e);
		return ret;
	}

	void test() {
		int N; cin >> N; //��ǥ �� �Է�
		
		set<Point> s;
		for (int i = 0; i < N; i++) {
			int x, y; cin >> x >> y; //��ǥ �Է¹ޱ�
			s.insert({ x, y }); //��ǥ�� set���� �־� �ߺ��� �����Ѵ�.
		}

		vector<Point> v = setToVector(s); //set�� vector�� ��ȯ

		long long maxArea = 0; //���簢���� �ִ� ����

		//��ǥ���� �ߺ����� ���� �� �� 2���� �̾� ���簢���� ����⸦ �õ��غ���.
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v.size(); j++) {

				if (i == j) continue; //���� ���� ������
				long long area = v[i].getSquaredDist(v[j]); //�� �� �Ÿ��� ������ �� ���簢�� ���̰� ��
				if (maxArea > area) continue; //������ ���� �ִ밪���� �۴ٸ� �ǳʶٱ�

				//�� ���� x, y ��ȭ���� ����Ѵ�.
				int dx = v[j].x - v[i].x;
				int dy = v[j].y - v[i].y;

				//���� (dx, dy)�� 90�� ȸ����Ű�� (-dy, dx)�� �ǹǷ�
				//�� ���͸� ���� ���� �����ָ� ���簢���� ������ �� ���� ���� �� �ִ�.
				Point a({ v[i].x - dy, v[i].y + dx });
				Point b({ v[j].x - dy, v[j].y + dx });

				//�� ���� set�� ���ԵǾ� �ִٸ� v[i], v[j], a, b�� ���簢���� ���� �� �ִٴ� ���̴�.
				//�׷��� ������ ���簢���� ���� �� ����.
				if (s.find(a) == s.end() || s.find(b) == s.end())
					continue;

				//���簢���� ������ �ִ밪�� �����Ѵ�.
				maxArea = max(maxArea, area);
			}
		}

		//������ ����Ѵ�.
		cout << fixed << setprecision(2) << (double)maxArea << endl;
	}

	int main() {
		int T; cin >> T; //�׽�Ʈ���̽� �� �Է�
		while (T--) test(); //�׽�Ʈ ����
		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
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