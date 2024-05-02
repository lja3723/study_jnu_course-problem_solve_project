//소프트웨어공학과 201986 이장안
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

namespace week9_histogram {

	//히스토그램 바를 표현한다.
	struct Bar {
		int pos; //바의 위치
		int height; //바의 높이
	};

	//주어진 입력에 대해 히스토그램에서 가능한 최대 넓이를 구하는 함수
	void histogram() {

		/* 입력: 기둥 수 N을 입력받는다. */
		int N; cin >> N; 
		vector<Bar> bar(N + 2);		//기둥 수를 저장할 배열 (왜 +2인지는 아래에서 설명)
		bar[0] = { 0, 0 };			//앞으로의 계산의 편의를 위해, 히스토그램 양 옆에 
		bar[N + 1] = { N + 1, 0 };	//높이가 0인 기둥이 각각 1개씩 있다고 가정한다.

		/* 입력: 기둥을 입력받는다. */
		for (int i = 1; i <= N; i++) 
		{
			cin >> bar[i].height; //기둥의 높이를 입력받는다.
			bar[i].pos = i; //기둥의 위치를 초기화한다.
		}


		/* 계산: 입력을 이용하여, 넓이의 최대값을 계산한다. */
		long long areaMax = 0;	//주어진 히스토그램에서 구할 수 있는 직사각형의 최대 넓이이다.
		stack<Bar> ableBars;	//히스토그램 막대들 중 현재 상황에서 직사각형을 만들 수 있는 바의 리스트들이다.
		ableBars.push(bar[0]);	//정답을 편하게 구하기 위해, 히스토그램 가장 맨 왼쪽에 높이 0인 막대가 있다고 가정한다.

		//히스토그램의 각 막대에 대해 아래 작업을 반복한다.
		for (int i = 1; i <= N + 1; i++) {

			//현재 가능한 막대 리스트(ableBars)에는 계산 편의를 위해 길이가 0인 막대가 하나 들어있기 때문에,
			//스택이 안 비어있는지 검사하기 위해선 !empty()가 아닌 size가 2 이상인지 확인해야 한다.
			//스택이 안 비어있는 경우, 현재 막대 길이보다 스택의 top에 들어있는 막대의 길이가 길다면
			//스택에 남아있는 막대의 길이가 현재 막대 길이와 같아질 때까지 스택에서 막대를 제거해야 한다.
			//제거하면서, 넓이를 구하는 프로세스를 수행한다.
			while (ableBars.size() > 1 && ableBars.top().height > bar[i].height) {
				//확장 중이던 히스토그램
				//이전에 가장 높았던 막대의 길이를 가져오고, 그 막대를 스택에서 제거한다.
				long long height = ableBars.top().height; 
				ableBars.pop();

				//그 이전의 히스토그램
				//현재 확인 중인 막대의 위치와, 스택에 남아있던 두 번째로 높은 막대의 위치를 이용하여
				//구하고자 하는 넓이의 가로를 계산한다.
				long long width = abs(bar[i].pos - (ableBars.top().pos + 1));

				//가능한 면적을 구한 뒤, 면적이 최대값이라면 기존 areaMax를 갱신한다.
				long long area = height * width;
				areaMax = max(areaMax, area);
			}

			//현재 보고 있는 막대를 스택에 추가한다.
			ableBars.push(bar[i]);
		}

		/* 출력: 구해진 정답을 출력한다. */
		cout << "answer: " << areaMax << endl;
	}

	int main() {
		int T; cin >> T; //테스트케이스를 입력받는다.
		while (T--) histogram(); //테스트를 T회 실행한다.
		return 0;
	}
}

//문제풀이를 담당하는 main문을 호출한다.
int main() { return week9_histogram::main(); }

/*
	>> input
2
7
2 1 4 5 1 3 3
4
1000 1000 1000 1000
	<< output
8 4000
*/