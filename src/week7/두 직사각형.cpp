//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>

using namespace std;

namespace week7_two_rectangles {

	struct Point { int x, y; }; //2���� ���� ǥ���ϴ� ����ü

	struct Rect { int left, right, top, bottom; }; //���簢���� ǥ���ϴ� ����ü

	//�� ���簢���� ���� ���̸� ���ϴ� �Լ�
	int get_cross_area(const Rect& a, const Rect& b) {
		Rect cross; //�����ϴ� ���簢�� ����

		cross.left	 = max(a.left, b.left); //���� ���簢���� left = �� ���簢�� left �� �� ū ����
		cross.right	 = min(a.right, b.right); //���� ���簢���� right = �� ���簢�� right �� �� ���� ����
		cross.top	 = min(a.top, b.top); //���� ���簢���� top = �� ���簢�� top �� �� ���� ����
		cross.bottom = max(a.bottom, b.bottom); //���� ���簢���� bottom = �� ���簢�� bottom �� �� ū ����

		//right - left: ������ ����, ���� ���� ������� 0�� ���Ѵ�. (max �Լ��� ������ �̿�)
		//top - bottom: ������ ����, ���� ���� ������� 0�� ���Ѵ�. (max �Լ��� ������ �̿�)
		//�� ���� ���� ���� �� ���ϰ��� �ϴ� �����̴�.
		return max(0, cross.right - cross.left) * max(0, cross.top - cross.bottom);
	}
		 
	int main() {
		int T; cin >> T; //�׽�Ʈ���̽� �� T �Է�

		while (T--) {
			//�� a, b, p, q�� ��ǥ ������ �Է¹޴´�.
			Point a, b, p, q;
			cin >> a.x >> a.y >> b.x >> b.y;
			cin >> p.x >> p.y >> q.x >> q.y;

			//���� ���� ������ ���簢���� ���� ����(left right top bottom)�� ��ȯ�Ѵ�.

			Rect ra; //�� a, b�� ������ ù��° ���簢�� a
			ra.left		= min(a.x, b.x); //�� ���� x��ǥ �� ���� ���� left
			ra.right	= max(a.x, b.x); //ū ���� right
			ra.top		= max(a.y, b.y); //�� ���� y��ǥ �� ū ���� top
			ra.bottom	= min(a.y, b.y); //���� ���� bottom

			Rect rb; //�� a, b�� ������ �ι�° ���簢�� b
			rb.left		= min(p.x, q.x); //�� ���� x��ǥ �� ���� ���� left
			rb.right	= max(p.x, q.x); //ū ���� right
			rb.top		= max(p.y, q.y); //�� ���� y��ǥ �� ū ���� top
			rb.bottom	= min(p.y, q.y); //���� ���� bottom

			//�� ���簢���� �������� �����ϴ� ������ ���̸� ���Ѵ�.
			cout << get_cross_area(ra, rb) << endl;
		}

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
//int main() { return week7_two_rectangles::main(); }

/*
	>> input
1
1 1 3 3 4 2 2 4
	<< output
1
*/