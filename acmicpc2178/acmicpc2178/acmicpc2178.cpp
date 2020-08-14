
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int M, N;
vector<vector <int>> map;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin >> M;
	
	for (int i = 0; i < N; i++) {
		vector<int> v;
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			v.push_back(str[j] - 48);
		}
		map.push_back(v);
	}
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	while (!q.empty()) {
		pair<int, int> fr = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dr = fr.first + dir[i][0];
			int dc = fr.second + dir[i][1];
			if (dr >= 0 && dr < N && dc >= 0 && dc < M) {
				if (map[dr][dc] != 0 &&( map[dr][dc] == 1 || map[dr][dc] + 1 < map[fr.first][fr.second]) ) {
					map[dr][dc] = map[fr.first][fr.second] + 1;
					q.push({ dr, dc });
				}
			}
		}
	}

	cout << map[N - 1][M - 1];
	
}
