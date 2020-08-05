#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int N, V;
vector<vector<int>> dir = { {-1,0},{1, 0},{0, -1}, {0, 1} };//상하좌우

vector<vector<int>> map(25, vector<int>(25, 0));
vector<int> ans(640, 0);

int cnt = 0;

void dfs(int a, int b, int next) {
	map[a][b] = next;

	for (int i = 0; i < 4; i++) {
		int dy = a + dir[i][0];
		int dx = b + dir[i][1];
		if (dy >= 0 && dy < N && dx >= 0 && dx < N) {
			if (map[dy][dx] == 1) {
				dfs(dy, dx, next);
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
			if (map[i][j] == 1) {
				cnt++;
				dfs(i, j, cnt + 1);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] > 1) {
				ans[map[i][j] - 2]++;
			}
		}
	}
	
	sort(ans.begin(), ans.end());

	cout << cnt << endl;
	for (int i = 0; i < 640; i++) {
		if (ans[i] > 0) {
			cout << ans[i] << endl;

		}
	}

	return 0;
}
