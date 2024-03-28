//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

namespace week4_bubble_sort {
	
	//주어진 컨테이너를 오름차순으로 버블 정렬한다.
	void bubbleSort(vector<int>& data) {

		int n = data.size(); //버블 정렬을 실시할 컨테이너의 길이를 구한다.

		//이중 반복문을 이용하여 모든 원소를 훑는다.
		for (int i = n; i >= 0; i--) {
			//인덱스 1부터 시작해, 자신의 왼쪽 원소와 자신을 비교한다.
			for (int j = 1; j < i; j++)
				//인접한 두 데이터가 오름차순 조건을 위배하는 경우
				if (data[j - 1] > data[j]) { 
					//임시변수 tmp를 이용해 두 데이터의 swap을 실시한다.
					int tmp = data[j - 1];
					data[j - 1] = data[j];
					data[j] = tmp;
				}
		}
	}

	//컨테이너(vector<int>)를 표준 출력으로 출력한다.
	void printVector(const vector<int>& data) {
		//첫 번째 원소를 우선 출력한다.
		if (!data.empty()) cout << data[0];

		//두 번째 원소부터는 공백을 첨가하여 출력한다.
		for (int i = 1; i < data.size(); i++)
			cout << " " << data[i];
		cout << endl; //개행 출력으로 마무리한다.
	}

	int main() {
		int n; cin >> n; //데이터 개수를 받는다.
		vector<int> data(n); //데이터 저장 컨테이너를 초기화한다.
		
		for (int i = 0; i < n; i++) 
			cin >> data[i]; //컨테이너에 n개의 데이터를 저장한다.

		//컨테이너를 버블정렬 알고리즘을 이용해 오름차순으로 정렬한다.
		bubbleSort(data);

		//컨테이너의 내용을 출력한다.
		printVector(data);

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다. (주석 해제 후 실행)
//int main() { return week4_bubble_sort::main(); }

/*
	>> input
5
3 5 1 2 4
	<< output
1 2 3 4 5
*/