//����Ʈ������а� 201986 �����
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

namespace week4_bubble_sort {
	
	//�־��� �����̳ʸ� ������������ ���� �����Ѵ�.
	void bubbleSort(vector<int>& data) {

		int n = data.size(); //���� ������ �ǽ��� �����̳��� ���̸� ���Ѵ�.

		//���� �ݺ����� �̿��Ͽ� ��� ���Ҹ� �ȴ´�.
		for (int i = n; i >= 0; i--) {
			//�ε��� 1���� ������, �ڽ��� ���� ���ҿ� �ڽ��� ���Ѵ�.
			for (int j = 1; j < i; j++)
				//������ �� �����Ͱ� �������� ������ �����ϴ� ���
				if (data[j - 1] > data[j]) { 
					//�ӽú��� tmp�� �̿��� �� �������� swap�� �ǽ��Ѵ�.
					int tmp = data[j - 1];
					data[j - 1] = data[j];
					data[j] = tmp;
				}
		}
	}

	//�����̳�(vector<int>)�� ǥ�� ������� ����Ѵ�.
	void printVector(const vector<int>& data) {
		//ù ��° ���Ҹ� �켱 ����Ѵ�.
		if (!data.empty()) cout << data[0];

		//�� ��° ���Һ��ʹ� ������ ÷���Ͽ� ����Ѵ�.
		for (int i = 1; i < data.size(); i++)
			cout << " " << data[i];
		cout << endl; //���� ������� �������Ѵ�.
	}

	int main() {
		int n; cin >> n; //������ ������ �޴´�.
		vector<int> data(n); //������ ���� �����̳ʸ� �ʱ�ȭ�Ѵ�.
		
		for (int i = 0; i < n; i++) 
			cin >> data[i]; //�����̳ʿ� n���� �����͸� �����Ѵ�.

		//�����̳ʸ� �������� �˰����� �̿��� ������������ �����Ѵ�.
		bubbleSort(data);

		//�����̳��� ������ ����Ѵ�.
		printVector(data);

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�. (�ּ� ���� �� ����)
//int main() { return week4_bubble_sort::main(); }

/*
	>> input
5
3 5 1 2 4
	<< output
1 2 3 4 5
*/