
#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
int R, C;

vector<vector<int>> map(501, vector<int>(501, 0));
vector<vector<int>> dp(501, vector<int>(501, -1));

int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
int ans = 0;

int dfs(int r, int c) {
	if (r == R - 1 && c == C - 1) {
		return 1;
	}

	if (dp[r][c] == -1) {
		dp[r][c] = 0;
		for (int d = 0; d < 4; d++) {
			int dr = r + dir[d][0];
			int dc = c + dir[d][1];
			if (dr >= 0 && dr < R && dc >= 0 && dc < C) {
				if (map[r][c] > map[dr][dc]) {
					dp[r][c] += dfs(dr, dc);
				}

			}
		}
	}
	return dp[r][c];
}

int main() {
	cin >> R >> C;


	for (int r = 0; r < R; r++) {

		for (int c = 0; c < C; c++) {
			cin >> map[r][c];
		}
	}

	cout << dfs(0, 0);


}