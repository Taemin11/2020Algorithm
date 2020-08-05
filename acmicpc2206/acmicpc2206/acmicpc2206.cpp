
#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, M;
vector<vector<int>> map(1001, vector<int>(1001, 0));
vector<vector<int>> mapo(1001, vector<int>(1001, 0));

int dir[4][2] = { {-1, 0},{1, 0}, {0, -1}, {0, 1} };
int mins = 1002;
void bfs() {

	queue<vector<int>> q;
	q.push({ 1, 0 });
	
	while (!q.empty()) {
		vector<int> fr = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int dr = fr[0] + dir[k][0];
			int dc = fr[1] + dir[k][1];

			if (dr >= 1 && dr <= N && dc >= 1 && dc <= M && map[dr][dc] == 0) {
				map[dr][dc] = map[fr[0]][fr[1]] + 1;
				if (map[dr][dc] >= mins) {
					break;
				}
				vector<int> input = { dr, dc };
				q.push(input);
			}
		}
	}
	
}


int main()
{

	queue<int> q;

	cin >> N;
	cin >> M;
	
	string str[1001];
	for (int i = 1; i <= N; i++) {
		cin >> str[i-1];
		for (int j = 1; j <= M; j++) {
			mapo[i][j] = static_cast<int>(str[i-1][j-1] - 48);
			
		}
	}
	map = mapo;
	bfs();
	if (map[N][M] != 0 && mins > map[N][M]) {
		mins = map[N][M];
	}
	map = mapo;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 1) {
				for (int k = 0; k < 2; k++) {
					int dr1 = i + dir[k * 2][0];
					int dc1 = j + dir[k * 2][1];
					int dr2 = i + dir[k * 2 + 1][0];
					int dc2 = j + dir[k * 2 + 1][1];
					if (dr1 >= 1 && dr1 <= N && dc1 >= 1 && dc1 <= M &&
						dr2 >= 1 && dr2 <= N && dc2 >= 1 && dc2 <= M &&
						map[dr1][dc1] == 0 && map[dr2][dc2] == 0) {
						map[i][j] = 0;
						bfs();
						if (map[N][M] != 0 && mins > map[N][M]) {
							mins = map[N][M];
						}
						map = mapo;
					}
				}
			}			
		}
	}	
	if (mins == 1002) {
		mins = -1;
	}
	cout << mins;
}
