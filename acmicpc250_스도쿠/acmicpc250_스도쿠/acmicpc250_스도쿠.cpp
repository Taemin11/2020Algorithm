#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map(9, vector<int>(9, 0));
vector<vector<int>> rows(9, vector<int>(10, 0));
vector<vector<int>> cols(9, vector<int>(10, 0));
vector<vector<int>> rooms(9, vector<int>(10, 0));
bool fire = false;

void dfs(int r, int c) {

	int num_room = (r / 3) * 3 + (c / 3);
	if (r == 9 && c == 0) {
		fire = true;
		return;
	}

	if (map[r][c] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (!rows[r][i] && !cols[c][i] && !rooms[num_room][i]) {

				rows[r][i] = 1;
				cols[c][i] = 1;
				rooms[num_room][i] = 1;
				map[r][c] = i;
				int dr = r;
				int dc = c + 1;
				if (dc == 9) {
					dr++;
					dc = 0;
				}
				dfs(dr, dc);
				if (fire) {
					return;
				}
				rows[r][i] = 0;
				cols[c][i] = 0;
				rooms[num_room][i] = 0;
				map[r][c] = 0;
			}
		}
	}
	else {
		int dr = r;
		int dc = c + 1;
		if (dc == 9) {
			dr++;
			dc = 0;
		}
		dfs(dr, dc);
		if (fire) {
			return;
		}
	}
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int input = 0;
			cin >> input;
			if (input != 0) {
				map[i][j] = input;
				rows[i][input] = 1;
				cols[j][input] = 1;
				int r = (i / 3) * 3;
				int c = (j / 3);
				rooms[r + c][input] = 1;
			}
		}
	}
	dfs(0, 0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			cout << map[i][j] << " ";
		}
		cout << "\n";
	}


}
