#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int N, M;
	cin >> N;
	cin >> M;
	vector<vector<int>> A(N, vector<int>(M, 0));
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			cin >> A[row][col];
		}
	}

	int K;
	cin >> M;
	cin >> K;
	vector<vector<int>> B(M, vector<int>(K, 0));
	for (int row = 0; row < M; row++) {
		for (int col = 0; col < K; col++) {
			cin >> B[row][col];
		}
	}

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < K; col++) {
			int sum = 0;
			for (int i = 0; i < M; i++) {
				sum += A[row][i] * B[i][col];
			}
			cout << sum << " ";
		}
		cout << "\n";
	}
}

