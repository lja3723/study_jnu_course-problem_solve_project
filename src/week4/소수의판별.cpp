//소프트웨어공학과 201986 이장안
#include <cstdio>
#include <iostream>

using namespace std;

namespace week4_prime_number_determination {

	bool isPrime(int N) {
		return false;
	}

	int main() {
		int T;
		cin >> T;

		for (int i = 1; i <= T; i++) {
			cout << "Case #" << i << endl;
			int n;
			cin >> n;
			cout << (isPrime(n) ? "YES" : "NO") << endl;
		}

		return 0;
	}

}

//int main() { return week4_prime_number_determination::main(); }

/*
	>> input
0
	<< output
0
*/