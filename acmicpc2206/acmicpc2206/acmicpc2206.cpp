#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
int N, M;
int map[1001][1001];
bool visit[1001][1001][2];

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
	visit[0][0][0] = true;

	while (!q.empty()) {
		int row = q.front().first.first;
		int col = q.front().first.second;
		int b = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (row == N - 1 && col == M - 1) {
			return cnt;
		}
		for (int i = 0; i < 4; i++) {
			int dr = row + dir[i][0];
			int dc = col + dir[i][1];

			if (dr >= 0 && dr < N && dc >= 0 && dc < M) {
				if (map[dr][dc] == 1 && b == 0) { //벽이 있고 벽을 부순적이 없을 때
					visit[dr][dc][1] = true;
					q.push(make_pair(make_pair(dr, dc), make_pair(1, cnt + 1)));
				}
				else if (map[dr][dc] == 0 && visit[dr][dc][b] == false) {
					visit[dr][dc][b] = true;
					q.push(make_pair(make_pair(dr, dc), make_pair(b, cnt + 1)));
				}
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string n;
		cin >> n;
		for (int j = 0; j < M; j++) {
			map[i][j] = n[j] - 48;
		}
	}

	int ans = bfs();
	cout << ans;
}