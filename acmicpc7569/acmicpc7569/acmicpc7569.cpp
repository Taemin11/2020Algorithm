#include "pch.h"
#include <iostream>
#include <queue>

using namespace std;
int dir[6][3] = { {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };
int M, N, H;
int box[101][101][101];
int cntMax;


typedef struct {
	int i;
	int j;
	int h;
}Pos;

queue<Pos> q;
void init() {
	for (int h = 0; h < 101; h++) {
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				box[i][j][h] = 0;
			}
		}
	}
}

void bfs() {
	while (!q.empty()) {
		int row = q.front().i;
		int col = q.front().j;
		int high = q.front().h;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int dr = row + dir[i][0];
			int dc = col + dir[i][1];
			int dh = high + dir[i][2];
			if (dr >= 0 && dr < N && dc >= 0 && dc < M && dh >= 0 && dh < H) {
				if (box[dr][dc][dh] == 0) {
					box[dr][dc][dh] = box[row][col][high] + 1;
					if (cntMax < box[dr][dc][dh]) {
						cntMax = box[dr][dc][dh];
					}
					q.push({ dr,dc,dh });
				}
			}
		}
	}
}

int main()
{
	init();
	cntMax = 1;
	
	cin >> M >> N >> H;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int n;
				cin >> n;
				box[i][j][h] = n;
				if (n == 1) {
					q.push({ i, j, h });
				}
			}
		}
	}

	bfs();

	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (box[i][j][h] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << cntMax - 1;
	return 0;

}

