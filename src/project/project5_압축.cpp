//소프트웨어공학과 201986 이장안
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

namespace jnu_project5_compression {

	const int MAX_INT = 0x7FFFFFFF;
	const int LEV_CNT = 4; //레벨의 개수
	const int LEV[LEV_CNT] = { 1, 86, 172, 256 }; //각 레벨에 해당하는 상수값
	const string LEV_STR[LEV_CNT] = { "00", "01", "10", "11" }; //각 레벨에 해당하는 비트


	//에러, 코드, 가중치로 변환비용을 계산하는 함수
	inline static int ConvertionCost(const int& err, const int& W, const int& code) {
		return err + W * code; //변환비용 수식에 의해 계산한다.
	}

	// 정수 a, b 사이의 에러를 계산하는 함수
	inline static int GetError(const int& a, const int& b) {
		return abs(a - b);
	}

	//문제를 풀이한다.
	//	N: 수열의 길이	
	//	W: 가중치
	//	seq_in: 초기 수열
	inline static void solution(int N, int W, const vector<int>& seq_in) {

		//중간에 계산된 최소 비용을 저장하는 동적 프로그래밍 배열
		//cost_min[i][j]의 의미:
		//	i: 0~3의 범위로, 수열의 마지막 수가 몇번째 레벨로 변환되었는지를 나타냄
		//	j: 0~N-1의 범위로, seq_in을 0부터 j-1번째까지 고려했을 때 비용의 최소값을 나타냄
		//		ex) cost_min[2][3]: seq_in 변환 시 맨 마지막 수를 2번째 레벨(172)로 변환한 상황에서 4번째 수열까지 고려하였을 때 비용의 최소값 
		vector<vector<int>> cost_min(LEV_CNT, vector<int>(N, MAX_INT));

		//cost_min[i][j]가 최소값이 되게 만들었던 cost_min[i][j-1]의 인덱스 i를 저장하는 배열로 경로 추적용
		//	ex) path[2][3] == 1이면 cost_min[2][3]가 최소값이 되게한 이전 계산 결과는 cost_min[1][2] 였다는 것임
		vector<vector<int>> path(LEV_CNT, vector<int>(N, -1));

		//DP의 초기값을 설정한다.
		//수열 길이가 1인 경우, cost_min[level][0]의 값은 유일하게 정해진다.
		for (int lv = 0; lv < LEV_CNT; lv++) {
			//수열 길이가 1일 때 첫 코드 길이는 무조건 2이다.
			cost_min[lv][0] = ConvertionCost(GetError(seq_in[0], LEV[lv]), W, 2);
		}

		//DP의 나머지를 계산한다.
		//수열의 두번째 수부터 마지막 수까지 계산한다.
		for (int n = 1; n < N; n++) {
			//현재 레벨
			for (int lv_cur = 0; lv_cur < LEV_CNT; lv_cur++) {
				//이전 레벨
				for (int lv_prev = 0; lv_prev < LEV_CNT; lv_prev++) {
					//현재 고려중인 경우에 대해 이전 레벨과 현재 레벨이 같으면 코드의 길이는 1만 늘어나고,
					//레벨이 다르면 "1"을 추가한 뒤 2비트 코드를 추가하므로 코드의 길이는 3이 늘어난다. 이것을 계산한다.
					int code_len = lv_cur == lv_prev ? 1 : 3;
					
					//현재 고려중인 경우에 대한 변환 비용 증분을 계산한다.
					int cost_diff = ConvertionCost(GetError(seq_in[n], LEV[lv_cur]), W, code_len);
					
					//현재 고려중인 경우의 변환 비용을 계산한다.
					int cost = cost_min[lv_prev][n - 1] + cost_diff;
					
					//현재 고려중인 경우가 변환 비용의 최소값이면, 최소비용을 갱신한다.
					if (cost < cost_min[lv_cur][n]) {
						cost_min[lv_cur][n] = cost; //현재 고려중인 경우의 최소비용 갱신
						path[lv_cur][n] = lv_prev;  //나중에 실제 코드를 탐색하기 위한 경로 저장
					}
				}
			}
		}

		//N-1번째 수를 고려했을 경우의 모든 변환최소비용이 계산되었다.
		//가능한 LEV_CNT가지(4가지) 경우 중 변환비용이 제일 작은 경우와 그때의 인덱스를 계산한다.
		int cost_min_idx = 0;
		for (int lv = 0; lv < LEV_CNT; lv++) {
			//cost_min_idx가 가장 작은 최소비용을 가리키도록 업데이트한다.
			if (cost_min[lv][N - 1] < cost_min[cost_min_idx][N - 1]) {
				cost_min_idx = lv;
			}
		}

		//최소값 인덱스를 바탕으로 인덱스 경로를 추적하여,
		//변환비용이 최소가 될때의 변환된 수열을 복원한다.
		vector<int> seq_converted(N); //변환된 수열
		int last_idx = cost_min_idx;
		for (int n = N - 1; n >= 0; n--) {
			seq_converted[n] = LEV[last_idx]; //변환된 수열을 저장
			if (n != 0)
				last_idx = path[last_idx][n]; //n이 0이 아닌 경우에만 인덱스를 갱신
		}

		//변환된 수열을 사용하여 변환 코드를 생성한다.
		string code = LEV_STR[last_idx]; //첫 번째 수의 코드값
		for (int n = 1; n < N; n++) {
			//이전 수와 다른 경우 1을 추가하고 새 코드를 추가한다.
			if (seq_converted[n - 1] != seq_converted[n]) {
				for (int lv = 0; lv < LEV_CNT; lv++) {
					//n번째 수의 레벨을 구한 뒤, 해당하는 레벨의 코드를 추가한다.
					if (seq_converted[n] == LEV[lv]) {
						code += "1" + LEV_STR[lv]; //새 코드를 뒤에 추가한다.
						break;
					}
				}
			}
			else {
				//이전 수와 같은 경우 0을 추가한다.
				code += "0";
			}
		}

		//문제의 정답인 최소 비용과 해당하는 코드를 출력한다.
		cout << cost_min[cost_min_idx][N - 1] << endl;
		cout << code << endl;
	}

	/************************************************************************************/

	//주어진 작업의 수행시간을 측정한다.
	void measureProcessTime(function<void(void)> process) {
		clock_t duration = -clock(); //작업시간 측정 시작
		process(); //작업을 실행한다.
		duration += clock(); //작업시간 측정 종료
		cout.precision(3);
		cout << fixed << "실행시간: " << ((double)duration / CLOCKS_PER_SEC) << "초" << endl;
	}

	int main() {
		int N, W; cin >> N >> W; //수열 길이와 가중치를 입력받음
		vector<int> seq_in(N); //입력 수열
		//N개의 수열을 이루는 정수를 입력받는다.
		for (int i = 0; i < N; i++) cin >> seq_in[i];

		//인자로 들어온 모든 코드의 실행시간을 측정한뒤, 출력한다.
		measureProcessTime([&](){ solution(N, W, seq_in); });

		return 0;
	}

}

//문제풀이를 담당하는 main문을 호출한다.
int main() { return jnu_project5_compression::main(); }

/*
	>> input
8 100
2
2
2
2
2
46
2
2
	<< output
952
000000000
실행시간: xxx초
*/