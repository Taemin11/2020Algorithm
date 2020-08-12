#include "pch.h"
#include <iostream>
#include <queue>

using namespace std;

int M, N, K;
int map[51][51];
bool visit[51][51];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };


void init() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			map[i][j] = 0;
			visit[i][j] = false;
		}
	}
}

int bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dr = row + dir[i][0];
			int dc = col + dir[i][1];
			if (dr >= 0 && dr < N && dc >= 0 && dc < M) {
				if (map[dr][dc] == 1 && visit[dr][dc] == false) {
					q.push(make_pair(dr, dc));
					visit[dr][dc] = true;
				}
			}
		}
	}
	return 1;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> M >> N >> K;

		init();

		for (int i = 0; i < K; i++) {
			int r, c;
			cin >> c >> r;
			map[r][c] = 1;
		}
		int ans = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1 && visit[i][j] == false) {
					ans += bfs(i, j);
				}
			}
		}
		cout << ans << "\n";
	}


}