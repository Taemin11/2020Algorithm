#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, V;
vector<vector<int>> nodes(101, vector<int>(101, 0));
vector<bool> checked(101, false);
int cnt;
void bfs(int covid) {
	queue<int> q;
	q.push(covid);
	checked[covid] = true;
	while (!q.empty()) {
		int fronts = q.front();
		checked[fronts] = true;
		cnt++;
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (!checked[i] && nodes[fronts][i] == 1) {				
				q.push(i);
				checked[i] = true;
			}
		}
	}
}
int main()
{
	cin >> N;
	cin >> V;
	int s, e;
	for (int i = 0; i < V; i++) {
		cin >> s;
		cin >> e;
		nodes[s][e] = 1;
		nodes[e][s] = 1;
	}
	cnt = 0;
	bfs(1);
	cout << cnt - 1;

}
