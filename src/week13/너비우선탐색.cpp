//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

namespace week13_bfs {

	int map[10][10] = { 0 }; //그래프 인접 행렬
	int visit[10] = { 0 }; //노드 방문 여부 저장
	queue<int> q; //너비우선탐색을 수행하기 위한 큐
	int num, edge_num; //노드 수, 간선 수

	//너비 우선 탐색을 v번 노드부터 시작하는 함수
	void bfs(int v) {
		//현재 방문중인 노드를 출력한다.
		cout << v << endl;
		q.push(v); //그 노드를 큐에 넣는다.

		//큐가 빌 때까지 반복
		while (!q.empty()) {
			//큐의 제일 앞의 원소를 꺼내온다.
			//현재 방문하는 노드이다.
			int node = q.front(); q.pop();

			//큐에서 꺼내온 노드와 연결된 모든 노드를 탐색한다.
			for (int i = 0; i < num; i++) {
				//node와 i가 연결되었고, i가 아직 방문하지 않으면 실행한다.
				if (map[node][i] && !visit[i]) {
					visit[node] = 1; //현재 방문중인 노드를 방문했다고 표시한다.
					//현재 방문중인 i노드를 출력한다.
					cout << i << endl;
					//현재 노드와 연결된 노드 i를 다음에 방문할 수 있도록 큐에 추가한다.
					q.push(i);
				}
			}
		}
	}

	int main() {
		//노드와 간선의 수를 입력받는다.
		cin >> num >> edge_num;

		//간선의 수만큼 데이터 입력받음
		for (int i = 0; i < edge_num; i++) {
			int v1, v2;
			cin >> v1 >> v2; //간선 연결정보를 입력 받는다.
			//v1, v2 노드를 연결되었다고 표시한다.
			//무방향 그래프이므로, a->b가 연결되었으면 b->a도 연결한다.
			map[v1][v2] = map[v2][v1] = 1;
		}

		//너비 우선 탐색을 1번 노드부터 시작한다.
		bfs(1);

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
//int main() { return week13_bfs::main(); }

/*
	>> input
8 10
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
3
4
5
6
7
*/