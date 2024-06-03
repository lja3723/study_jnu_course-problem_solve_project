//����Ʈ������а� 201986 �����
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

namespace jnu_project5_compression {

	const int MAX_INT = 0x7FFFFFFF;
	const int LEV_CNT = 4; //������ ����
	const int LEV[LEV_CNT] = { 1, 86, 172, 256 }; //�� ������ �ش��ϴ� �����
	const string LEV_STR[LEV_CNT] = { "00", "01", "10", "11" }; //�� ������ �ش��ϴ� ��Ʈ


	//����, �ڵ�, ����ġ�� ��ȯ����� ����ϴ� �Լ�
	inline static int ConvertionCost(const int& err, const int& W, const int& code) {
		return err + W * code; //��ȯ��� ���Ŀ� ���� ����Ѵ�.
	}

	// ���� a, b ������ ������ ����ϴ� �Լ�
	inline static int GetError(const int& a, const int& b) {
		return abs(a - b);
	}

	//������ Ǯ���Ѵ�.
	//	N: ������ ����	
	//	W: ����ġ
	//	seq_in: �ʱ� ����
	inline static void solution(int N, int W, const vector<int>& seq_in) {

		//�߰��� ���� �ּ� ����� �����ϴ� ���� ���α׷��� �迭
		//cost_min[i][j]�� �ǹ�:
		//	i: 0~3�� ������, ������ ������ ���� ���° ������ ��ȯ�Ǿ������� ��Ÿ��
		//	j: 0~N-1�� ������, seq_in�� 0���� j-1��°���� ������� �� ����� �ּҰ��� ��Ÿ��
		//		ex) cost_min[2][3]: seq_in ��ȯ �� �� ������ ���� 2��° ����(172)�� ��ȯ�� ��Ȳ���� 4��° �������� ����Ͽ��� �� ����� �ּҰ� 
		vector<vector<int>> cost_min(LEV_CNT, vector<int>(N, MAX_INT));

		//cost_min[i][j]�� �ּҰ��� �ǰ� ������� cost_min[i][j-1]�� �ε��� i�� �����ϴ� �迭�� ��� ������
		//	ex) path[2][3] == 1�̸� cost_min[2][3]�� �ּҰ��� �ǰ��� ���� ��� ����� cost_min[1][2] ���ٴ� ����
		vector<vector<int>> path(LEV_CNT, vector<int>(N, -1));

		//DP�� �ʱⰪ�� �����Ѵ�.
		//���� ���̰� 1�� ���, cost_min[level][0]�� ���� �����ϰ� ��������.
		for (int lv = 0; lv < LEV_CNT; lv++) {
			//���� ���̰� 1�� �� ù �ڵ� ���̴� ������ 2�̴�.
			cost_min[lv][0] = ConvertionCost(GetError(seq_in[0], LEV[lv]), W, 2);
		}

		//DP�� �������� ����Ѵ�.
		//������ �ι�° ������ ������ ������ ����Ѵ�.
		for (int n = 1; n < N; n++) {
			//���� ����
			for (int lv_cur = 0; lv_cur < LEV_CNT; lv_cur++) {
				//���� ����
				for (int lv_prev = 0; lv_prev < LEV_CNT; lv_prev++) {
					//���� ������� ��쿡 ���� ���� ������ ���� ������ ������ �ڵ��� ���̴� 1�� �þ��,
					//������ �ٸ��� "1"�� �߰��� �� 2��Ʈ �ڵ带 �߰��ϹǷ� �ڵ��� ���̴� 3�� �þ��. �̰��� ����Ѵ�.
					int code_len = lv_cur == lv_prev ? 1 : 3;
					
					//���� ������� ��쿡 ���� ��ȯ ��� ������ ����Ѵ�.
					int cost_diff = ConvertionCost(GetError(seq_in[n], LEV[lv_cur]), W, code_len);
					
					//���� ������� ����� ��ȯ ����� ����Ѵ�.
					int cost = cost_min[lv_prev][n - 1] + cost_diff;
					
					//���� ������� ��찡 ��ȯ ����� �ּҰ��̸�, �ּҺ���� �����Ѵ�.
					if (cost < cost_min[lv_cur][n]) {
						cost_min[lv_cur][n] = cost; //���� ������� ����� �ּҺ�� ����
						path[lv_cur][n] = lv_prev;  //���߿� ���� �ڵ带 Ž���ϱ� ���� ��� ����
					}
				}
			}
		}

		//N-1��° ���� ������� ����� ��� ��ȯ�ּҺ���� ���Ǿ���.
		//������ LEV_CNT����(4����) ��� �� ��ȯ����� ���� ���� ���� �׶��� �ε����� ����Ѵ�.
		int cost_min_idx = 0;
		for (int lv = 0; lv < LEV_CNT; lv++) {
			//cost_min_idx�� ���� ���� �ּҺ���� ����Ű���� ������Ʈ�Ѵ�.
			if (cost_min[lv][N - 1] < cost_min[cost_min_idx][N - 1]) {
				cost_min_idx = lv;
			}
		}

		//�ּҰ� �ε����� �������� �ε��� ��θ� �����Ͽ�,
		//��ȯ����� �ּҰ� �ɶ��� ��ȯ�� ������ �����Ѵ�.
		vector<int> seq_converted(N); //��ȯ�� ����
		int last_idx = cost_min_idx;
		for (int n = N - 1; n >= 0; n--) {
			seq_converted[n] = LEV[last_idx]; //��ȯ�� ������ ����
			if (n != 0)
				last_idx = path[last_idx][n]; //n�� 0�� �ƴ� ��쿡�� �ε����� ����
		}

		//��ȯ�� ������ ����Ͽ� ��ȯ �ڵ带 �����Ѵ�.
		string code = LEV_STR[last_idx]; //ù ��° ���� �ڵ尪
		for (int n = 1; n < N; n++) {
			//���� ���� �ٸ� ��� 1�� �߰��ϰ� �� �ڵ带 �߰��Ѵ�.
			if (seq_converted[n - 1] != seq_converted[n]) {
				for (int lv = 0; lv < LEV_CNT; lv++) {
					//n��° ���� ������ ���� ��, �ش��ϴ� ������ �ڵ带 �߰��Ѵ�.
					if (seq_converted[n] == LEV[lv]) {
						code += "1" + LEV_STR[lv]; //�� �ڵ带 �ڿ� �߰��Ѵ�.
						break;
					}
				}
			}
			else {
				//���� ���� ���� ��� 0�� �߰��Ѵ�.
				code += "0";
			}
		}

		//������ ������ �ּ� ���� �ش��ϴ� �ڵ带 ����Ѵ�.
		cout << cost_min[cost_min_idx][N - 1] << endl;
		cout << code << endl;
	}

	/************************************************************************************/

	//�־��� �۾��� ����ð��� �����Ѵ�.
	void measureProcessTime(function<void(void)> process) {
		clock_t duration = -clock(); //�۾��ð� ���� ����
		process(); //�۾��� �����Ѵ�.
		duration += clock(); //�۾��ð� ���� ����
		cout.precision(3);
		cout << fixed << "����ð�: " << ((double)duration / CLOCKS_PER_SEC) << "��" << endl;
	}

	int main() {
		int N, W; cin >> N >> W; //���� ���̿� ����ġ�� �Է¹���
		vector<int> seq_in(N); //�Է� ����
		//N���� ������ �̷�� ������ �Է¹޴´�.
		for (int i = 0; i < N; i++) cin >> seq_in[i];

		//���ڷ� ���� ��� �ڵ��� ����ð��� �����ѵ�, ����Ѵ�.
		measureProcessTime([&](){ solution(N, W, seq_in); });

		return 0;
	}

}

//����Ǯ�̸� ����ϴ� main���� ȣ���Ѵ�.
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
����ð�: xxx��
*/