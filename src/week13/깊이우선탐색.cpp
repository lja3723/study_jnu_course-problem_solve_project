//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>

using namespace std;

namespace week13_dfs {

	int maps[10][10]; //그래프 인접 행렬
	int visited[10] = { 0 }; //노드 방문 여부 저장
	int num; //간선 정보의 수

	//깊이 우선 탐색을 v에서 실시하는 함수
	void dfs(int v) {
		//현재 방문중인 노드 번호 출력
		cout << v << endl;
		//현재 노드를 방문했다고 체크한다.
		visited[v] = 1;
		//노드 v와 연결된 모든 노드들을 탐색한다.
		for (int i = 0; i <= num; i++) {
			//v와 i가 연결되었고, i를 아직 방문하지 않은 경우 그 노드 i로 방문한다.
			if (maps[v][i] && !visited[i])
				dfs(i); //재귀적으로 실행
		}
	}

	int main() {
		cin >> num; //간선 정보의 수를 입력받음

		for (int i = 0; i < num; i++) {
			int v1, v2;
			cin >> v1 >> v2; //몇번 노드와 몇번 노드가 연결되었는지 입력받는다.
			//두 정점간 연결이 있다고 표시한다.
			//무방향 그래프이므로 a->b이면 b->a도 갈 수 있도록 표시한다.
			maps[v1][v2] = maps[v2][v1] = 1;
		}

		//깊이 우선 탐색을 1번 노드에서 시작한다.
		dfs(1);

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
//int main() { return week13_dfs::main(); }

/*
	>> input
10
1 2
1 3
2 4
2 5
4 8
5 8
3 6
3 7
6 8
7 8
	<< output
1
2
4
8
5
6
3
7
*/