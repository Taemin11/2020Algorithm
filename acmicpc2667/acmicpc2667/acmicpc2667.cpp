#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
int N, V;
vector<int> dir_row = { -1, 1, 0, 0 };//상하좌우
vector<int> dir_col = { 0, 0, -1, 1 };

vector<vector<int>> map(25, vector<int>(25, 0));
vector<vector<int>> checked(25, vector<int>(25, 0));
vector<int> ans(26, 0);
int cnt = 1;
void bfs(int row, int col) {
	queue<vector<int>> q;
	q.push({ row, col });
	checked[row][col] = cnt;
	while (!q.empty()) {
		vector<int> fronts = q.front();
		checked[fronts[0]][fronts[1]] = cnt;
		q.pop();
		int i = row;
		int j = col;
		if (checked[i][j] == cnt) {
			for (int k = 0; k < 4; k++) {
				if (i + dir_row[k] < 0 || i + dir_row[k] >= N || j + dir_col[k] < 0 || j + dir_col[k] >= N) {

				}
				else if (checked[i + dir_row[k]][j + dir_col[k]] != cnt && map[i + dir_row[k]][j + dir_col[k]] == 1) {
					q.push({ i + dir_row[k], j + dir_col[k] });
					checked[i + dir_row[k]][j + dir_col[k]] = cnt;
					row = i + dir_row[k];
					col = j + dir_col[k];
					ans[cnt]++;
				}
			}
		}


	}
}
int main()
{
	cin >> N;
	string str[26];
	for (int i = 0; i < N; i++) {
		cin >> str[i];
		for (int j = 0; j < N; j++) {
			map[i][j] = static_cast<int>(str[i][j] - 48);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (checked[i][j] == 0 && map[i][j] == 1) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt - 1 << "\n";
	for (int i = 1; i <= cnt; i++) {
		if (ans[i] > 0) {
			cout << ans[i] + 1 << "\n";
		}
	}

}
