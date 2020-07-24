#include <iostream>
#include <vector>
using namespace std;

int zero = 0;
int one = 0;

vector<int> cut(int start_row, int start_col, vector<vector<int>> paper, int N, int L, vector<int> color) {
	int count = 0;
	vector<int> colorTemp1(2, 0);
	vector<int> colorTemp2(2, 0);
	vector<int> colorTemp3(2, 0);
	vector<int> colorTemp4(2, 0);

	vector<vector<int>> dump(L, vector<int>(L, 0));
	int breakpoint = 0;
	for (int i = start_row; i < start_row + N; i++) {
		for (int j = start_col; j < start_col + N; j++) {
			dump[i][j] = paper[i][j];
		}
	}

	int comp = dump[start_row][start_col];

	for (int i = start_row; i < start_row + N; i++) {
		for (int j = start_col; j < start_col + N; j++) {
			if (dump[i][j] != comp) {
				breakpoint = 1;
				break;
			}
		}
		if (breakpoint == 1) {
			break;
		}
	}
	if (breakpoint == 1) {
		colorTemp1 = cut(start_row, start_col, dump, N / 2, L, color); //1
		colorTemp2 = cut(start_row, start_col + 2/ N, dump, N/2, L, color);//2
		colorTemp3 = cut(start_row + 2 / N, start_col, dump, N/2, L, color);//3	
		colorTemp4 = cut(start_row + 2 / N, start_col + 2 / N, dump, N/2, L, color);//4	
	}
	else {
		if (comp == 0) {
			color[0] += 1;
		}
		else {
			color[1] += 1;
		}
	}
	color[0] = color[0] + colorTemp1[0] + colorTemp2[0] + colorTemp3[0] + colorTemp4[0];
	color[1] = color[1] + colorTemp1[1] + colorTemp2[1] + colorTemp3[1] + colorTemp4[1];
	return color;
}

int main() {
	int N;
	vector<int> color(2, 0);
	cin >> N;
	vector<vector<int>> paper(N, vector<int>(N, 0));
	int cell = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cell;
			paper[i][j] = cell;
		}
	}
	color = cut(0, 0, paper, N, N, color);
	cout << color[0] << " ";
	cout << color[1];
	
}