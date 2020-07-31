#include <iostream>
#include <vector>
using namespace std;

vector<int> color(2, 0); //0 white 1 blue
vector<vector<int>> paper(128, vector<int>(128, 0));
void divide(int N, int r, int c) {


	int dif = paper[r][c];
	int difFlag = 0;
	for (int i = r; i < r+N; i++) {
		for (int j = c; j < c+N; j++) {
			if (paper[i][j] != dif) {
				difFlag = 1;
				break;
			}
		}
		if (difFlag == 1) {
			break;
		}
	}

	if (difFlag == 1) {
		divide( N / 2, r, c);
		divide( N / 2, r, c + N / 2);
		divide( N / 2, r + N / 2, c);
		divide( N / 2, r + N / 2, c + N / 2);
	}
	else {
		if (dif == 0) {
			color[0] += 1;
		}
		else {
			color[1] += 1;
		}
	}
}


int main() {
	int N;
	cin >> N;
	int cell = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	divide( N, 0, 0);
	cout << color[0] << " " << color[1];
	return 0;
}