
#include "pch.h"
#include<iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		long long answer = 0;
		vector<int> v(N, 0);
		for (int i = 0; i < N; i++) {
			int input;
			cin >> input;
			v[i] = input;
		}
		int max = v[N - 1];

		for (int i = N - 2; i >= 0; i--) {
			if (v[i] >= max) {
				max = v[i];
			}
			else {
				answer = answer + max - v[i];
			}
		}
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}