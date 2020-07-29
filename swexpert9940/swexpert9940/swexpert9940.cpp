#include "pch.h"
#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		int answer = 1;
		cin >> N;
		vector<int> v(N + 1, 0);
		for (int i = 0; i < N; i++) {
			int t;
			cin >> t;
			if (t > N) {
				answer = 0;
				break;
			}
			v[t] = 1;
		}

		for (int i = 1; i <= N; i++) {
			if (v[i] == 0 || answer == 0) {
				answer = 0;
				break;
			}
		}

		if (answer == 1) {
			cout << "#" << test_case << " " << "Yes" << "\n";
		}
		else {
			cout << "#" << test_case << " " << "No" << "\n";
		}
	}
	return 0;
}