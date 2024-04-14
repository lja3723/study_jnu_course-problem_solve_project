//소프트웨어공학과 201986 이장안

#include <iostream>
#include <functional>

using namespace std;

namespace jnu_project2_paper {

	//주어진 작업의 수행시간을 측정하는 클래스이다.
	class ProcessingTimeMeter {
	private:
		function<void(void)> process; //시간을 측정할 작업
	public:
		ProcessingTimeMeter(function<void(void)> process) : process(process) {}

		double measureTime() {
			clock_t duration = -clock(); //작업시간 측정 시작
			process(); //작업을 실행한다.
			duration += clock(); //작업시간 측정 종료

			return (double)duration / CLOCKS_PER_SEC; //측정된 작업시간(ms)를 리턴한다.
		}
	};


	//두 정수 a, b의 최대공약수를 구하는 알고리즘(유클리드 호제법)
	int gcd(int a, int b) {
		int r = a % b; //나머지 r을 구한 뒤

		if (r == 0) //a가 b로 나눠 떨어지면 최대 공약수는 b이다.
			return b;
		else //그게 아니면 a, b의 최대공약수는 b, r의 최대 공약수와 같다.
			return gcd(b, r);
	}


	void solve(int W, int H) {
		//W, H 직사각형을 살펴보면 대각선이 지나가는 정사각형 군집에 일정한 패턴이 있음을 알 수 있다.
		//입출력 예시에서는 그 군집의 개수가 4개인 것을 확인할 수 있는데, 이 개수는 W, H의 최대공약수임을 알 수 있다.
		//따라서 주어진 문제를 풀기 위해서는 W, H를 각각 최대공약수로 나눈 범위의 영역만 살펴보면 되는 것이다. 이때
		//W, H의 최대공약수를 g라 할 때, W' = W / g, H' = H' / g라고 하자.
		int g = gcd(W, H); //W, H의 최대공약수
		int ww = W / g;	//W'
		int hh = H / g;	//H'

		//그러면 W' * H' 크기의 직사각형에서 대각선이 지나가는 정사각형의 개수를 구하면 되는 것이다. 어떻게 구할까?
		//왼쪽 위 정사각형에서 오른쪽 아래 정사각형으로 대각선이 지나간다고 가정할 때, 대각선이 정사각형의 경계를 지나는 매 순간마다
		//대각선이 지나가는 정사각형의 개수가 1씩 증가하는 것을 알 수 있다. 이 때 지나가는 패턴을 잘 살펴보면
		//대각선은 세로 방향 경계를 W'-1 번 지나가고, 가로 방향 경계를 H'-1 번 지나감을 관찰할 수 있다.
		//즉 대각선은 (W'-1) + (H'-1) 개의 경계를 지나가므로, 대각선이 지나가는 정사각형 개수도 이와 같다.
		//처음 시작점에 한개의 정사각형이 있으므로, 대각선이 지나가는 정사각형의 총 개수를 p라고 하면
		//p = 1 + (W'-1) + (H'-1)이다.
		int p = 1 + (ww - 1) + (hh - 1); //대각선이 지나가는 정사각형의 총 개수

		//다시 W x H 정사각형을 생각해보면, 대각선이 지나가는 총 개수는 p개의 영역이 g개 있는 것과 같다고 볼 수 있다.
		//따라서 구하는 값은, 정사각형의 총 넓이 W*H에서 p*g를 뺀 값과 같다.
		//이때 W, H는 1억 이하의 정수이므로 답이 int의 최댓값으 넘을 수 있음을 유의한다.
		long long answer = (long long)W * H - p * g;

		//정답을 출력한다.
		cout << answer << endl;
	}


	int main() {
		int W, H;
		cin >> W >> H; //가로, 세로 길이를 입력받는다.

		//시간을 측정할 작업을 정의한다.
		ProcessingTimeMeter meter([W, H] { solve(W, H); });

		//작업의 수행 시간을 측정한 뒤, 수행 시간을 출력한다.
		printf("%실행시간: %.3lf초\n", meter.measureTime());
		return 0;
	}
}

//문제풀이를 담당하는 main문을 호출한다.
//int main() { return jnu_project2_paper::main(); }

/*
	>> input
8 12
	<< output
80
실행시간: xxx초
*/